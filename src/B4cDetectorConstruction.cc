//Compton and Two Photon Spectrometer (CATS) Construction
//Modified Geant4 exampleB4c

#include "B4cDetectorConstruction.hh"
#include "B4cCalorimeterSD.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"
#include "G4MultiUnion.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4AutoDelete.hh"
#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"



//The second line initializes the static member variable, "fMagFieldMessenger" of the class B4cDetectorConstruction.
//The "G4GlobalMagFieldMessenger*" lets us know that "fMagFieldMessenger" is a pointer of type G4GlobalMagFieldMessenger.
G4ThreadLocal
G4GlobalMagFieldMessenger* B4cDetectorConstruction::fMagFieldMessenger = 0; 

//This is the constructor of the class B4cDetectorConstruction. It initializes the member variables "fCheckOverlaps" and "fNofLayers".
B4cDetectorConstruction::B4cDetectorConstruction()
 : G4VUserDetectorConstruction(),
   fCheckOverlaps(true),
   fNofLayers(-1)
{
}

//Destructor
B4cDetectorConstruction::~B4cDetectorConstruction()
{ 
}  

//The presence of the parantheses after "Construct" lets us know that "Construct" is a method.
//It is a method that lives within the B4cDetectorConstruction class, and returns a pointer to G4VPhysicalVolume objects.
G4VPhysicalVolume* B4cDetectorConstruction::Construct()
{

  //This method calls the "DefineMaterials()" method, which defines the materials used in the detector
  DefineMaterials();
  

  //It also calls the "DefineVolumes" method, which defines the volumes of the detector (pretty much every part of the detector if you look at the code below.)
  //So, Construct() makes sure that materials are defined and volumes are constructed, and then returns the result of the DefineVolumes() method.
  //We have defined that the return type of this method is a pointer to G4VPhysicalVolume objects.
  //Therefore, Construct() returns a pointer to the top-level physical volume of the constructed detector (encapsulates the entire detector geometry.)
  //This pointer can then be used to interact the detector and other things.
  return DefineVolumes();
}



//we are defining a method named "DefineMaterials", belonging to the class B4cDetectorConstruction.
void B4cDetectorConstruction::DefineMaterials()
{ 
  //Lead materials defined using NIST Manager
  auto nistManager = G4NistManager::Instance();
  nistManager->FindOrBuildMaterial("G4_Pb");
  nistManager->FindOrBuildMaterial("G4_SODIUM_IODIDE");
  nistManager->FindOrBuildMaterial("G4_AIR");
  nistManager->FindOrBuildMaterial("G4_LITHIUM_CARBONATE");
  nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  nistManager->FindOrBuildMaterial("G4_C");

}

//Main construction of CATS starts here

//We are defining the method "DefineVolumes" belonging to the class B4cDetectorConstruction.
//"G4VPhysicalVolume*" lets us know that the return type of this method is a pointer that points to objects of G4VPhysicalVolume.
//So, if the return type of this method is a pointer to G4VPhysicalVolume, the return type of the Construct method obviously also has to point to G4VPhysicalVolume objects, since it returns the DefineVolumes method.
G4VPhysicalVolume* B4cDetectorConstruction::DefineVolumes()
{
  
  //This section of code gets the materials
  //auto means that the compiler is inferring the types of variables (i.e., auto x = 5 would lead the compiler to assign x as an integer.)
  auto defaultMaterial = G4Material::GetMaterial("G4_AIR");
  auto boxMaterial = G4Material::GetMaterial("G4_Pb");
  //auto gapMaterial = G4Material::GetMaterial("liquidArgon");
  auto coreMaterial = G4Material::GetMaterial("G4_SODIUM_IODIDE");
  auto ringMaterial = G4Material::GetMaterial("G4_LITHIUM_CARBONATE");
  auto scintMaterial = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  auto targetmaterial = G4Material::GetMaterial("G4_C");
    

  //A solid in G4 represents the geometric shape of a volume. It defines the spatial extent of an object in the simulation.

  //This creates a solid geometry representing the world volume using a box shape ("G4Box")
  //The dimensions of this box are 300cm x 300cm x 300cm (the arguments)
  //The solid is named "World"
  auto worldS = new G4Box("World", 300*cm, 300*cm, 300*cm);

  //A logical volume in G4 associates a solid with material properties. It represents the material composition and properties of the volume.
  
  //This creates a logical volume using the solid geometry ("WorldS"); it uses WorldS as its solid parameter
  //It is made from the "defaultMaterial", which is air, as defined above.
  //It is also named "World".  
  auto worldLV = new G4LogicalVolume(worldS, defaultMaterial, "World");
                                   
  //A physical volume in G4 creates a physical volume representing the placement of the world logical volume.
  
  //This line places the logical volume, "WorldLV", into the Geant4 simulation; it uses worldLV as its logical volume parameter
  //First Parameter: its rotation; set to no rotation
  //Second Parameter: its position; set to (0,0,0)
  //Third Parameter: its logical volume
  //Fourth Parameter: its name
  //Fifth Parameter: its mother volume; set to 0, meaning that "worldLV" is the top-level volume in this simulation
  //Sixth Parameter: boolean operation; set to none
  //Seventh Parameter: copy number
  //Eighth Parameter: checking overlaps
  auto worldPV = new G4PVPlacement(0, G4ThreeVector(), worldLV, "World", 0, false, 0, fCheckOverlaps);
  
  G4double z = 31.75*cm;
  G4double w = 40.75*cm;
  //Use pos1 to change the location of CATS, since it is used in the following code defining the pieces of CATS
  G4ThreeVector pos1 = G4ThreeVector(0, 0, 150*cm);

  //CATS Core
  //Summary: Creates a cylindrical volume representing the core of the detector, assigns material properties to it, and places it within the simulation environment.

  //This creates a cylindrical solid (G4Tubs) named "Core".
  //It has a radius from 0cm to 13.35cm.
  //It has a half-length of "z" (31.75cm as defined above.)
  //It starts at 0 degrees and has a sweep angle of 360 degrees (completes a full circle.)
  G4Tubs* Core = new G4Tubs("Core", 0*cm, 13.35*cm, z, 0.*deg, 360.*deg);

  //This creates a logical volume associated with the solid defined above (G4Tubs)
  //The first parameter specifies the solid geometry associated with the logical volume (here, it's the cylindrical solid named "Core" defined just above.)
  //The second parameter specifies the material as "coreMaterial" (specified earlier in code)
  //The third parameter gives this the name of "Core"
  G4LogicalVolume* logicCore = new G4LogicalVolume(Core, coreMaterial, "Core");

  //This line creates a physical volume placement representing the positioning of the logcal volume ("logicCore") within the simulation
  //First Parameter: rotation; 0 means none
  //Second Parameter: position; at position "pos1"
  //Third Parameter: logical volume; LV is logicCore
  //Fourth Parameter: name
  //Fifth Parameter: mother volume; mother volume of worldLV
  //Sixth Parameter: boolean operation; false, meaning no operation
  //Seventh Parameter: copy number
  //Eighth Parameter: whether to check for overlaps
  new G4PVPlacement(0, pos1, logicCore, "Core", worldLV, false, 1, fCheckOverlaps);

  //End of CATS Core construction
  

  //Constructing the target now by Laura Hubbert
  G4Box* target_box = new G4Box("Target", 10*cm, 10*cm, 10*cm);
  G4LogicalVolume* target_box_LV = new G4LogicalVolume(target_box, targetmaterial, "Target");

  G4ThreeVector target_position = G4ThreeVector(0,0,0);

  new G4PVPlacement(0, target_position, target_box_LV, "Target", worldLV, false, 1, fCheckOverlaps);

 
  //Start of Segmented Annulus construction
  
  //An annulus is a ring-shaped object.
  //The second parameter of each annulus object represents the inner radius, and the third represents the outer radius.
  //Inner radius: distance from center to the inner edge of the annulus
  //Outer radius: distance from center to the outer edge of the annulus

  G4Tubs* AnnulusPiece1 = new G4Tubs("AnnulusPiece1", 13.35*cm, 24.15*cm, z, 0.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece1 = new G4LogicalVolume(AnnulusPiece1, coreMaterial, "AnnulusPiece1");
  new G4PVPlacement(0, pos1, logicAnnulusPiece1, "AnnulusPiece1", worldLV, false, 2, fCheckOverlaps);

  G4Tubs* AnnulusPiece2 = new G4Tubs("AnnulusPiece2", 13.35*cm, 24.15*cm, z, 60.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece2 = new G4LogicalVolume(AnnulusPiece2, coreMaterial, "AnnulusPiece2");
  new G4PVPlacement(0, pos1, logicAnnulusPiece2, "AnnulusPiece2", worldLV, false, 3, fCheckOverlaps);

  G4Tubs* AnnulusPiece3 = new G4Tubs("AnnulusPiece3", 13.35*cm, 24.15*cm, z, 120.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece3 = new G4LogicalVolume(AnnulusPiece3, coreMaterial, "AnnulusPiece3");
  new G4PVPlacement(0, pos1, logicAnnulusPiece3, "AnnulusPiece3", worldLV, false, 4, fCheckOverlaps);

  G4Tubs* AnnulusPiece4 = new G4Tubs("AnnulusPiece4", 13.35*cm, 24.15*cm, z, 180.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece4 = new G4LogicalVolume(AnnulusPiece4, coreMaterial, "AnnulusPiece4");
  new G4PVPlacement(0, pos1, logicAnnulusPiece4, "AnnulusPiece4", worldLV, false, 5, fCheckOverlaps);

  G4Tubs* AnnulusPiece5 = new G4Tubs("AnnulusPiece5", 13.35*cm, 24.15*cm, z, 240.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece5 = new G4LogicalVolume(AnnulusPiece5, coreMaterial, "AnnulusPiece5");
  new G4PVPlacement(0, pos1, logicAnnulusPiece5, "AnnulusPiece5", worldLV, false, 6, fCheckOverlaps);

  G4Tubs* AnnulusPiece6 = new G4Tubs("AnnulusPiece6", 13.35*cm, 24.15*cm, z, 300.*deg, 60*deg);
  G4LogicalVolume *logicAnnulusPiece6 = new G4LogicalVolume(AnnulusPiece6, coreMaterial, "AnnulusPiece6");
  new G4PVPlacement(0, pos1, logicAnnulusPiece6, "AnnulusPiece6", worldLV, false, 7, fCheckOverlaps);

  //End of Segmented Annulus construction
  //Start of Lithium Carbonate Layer for Insulation construction
  
  G4Tubs* Ring = new G4Tubs("Ring", 24.15*cm, 25.15*cm, z, 0, 360*deg);
  G4LogicalVolume *logicRing = new G4LogicalVolume(Ring, ringMaterial, "Ring");
  new G4PVPlacement(0, pos1, logicRing, "Ring", worldLV, false, 8, fCheckOverlaps);

  //End of Lithium Carbonate Layer for Insulation construction
  //Start of Scintillators to veto Cosmic Rays construction

  G4Tubs *Scint1 = new G4Tubs("Scint1", 25.15*cm, 35.15*cm, w, 0, 72*deg);
  G4LogicalVolume *logicScint1 = new G4LogicalVolume(Scint1, scintMaterial, "Scint1");
  new G4PVPlacement(0, pos1, logicScint1, "Scint1", worldLV, false, 9, fCheckOverlaps);

  G4Tubs *Scint2 = new G4Tubs("Scint2", 25.15*cm, 35.15*cm, w, 72*deg, 72*deg);
  G4LogicalVolume *logicScint2 = new G4LogicalVolume(Scint2, scintMaterial, "Scint2");
  new G4PVPlacement(0, pos1, logicScint2, "Scint2", worldLV, false, 10, fCheckOverlaps);

  G4Tubs *Scint3 = new G4Tubs("Scint3", 25.15*cm, 35.15*cm, w, 144*deg, 72*deg);
  G4LogicalVolume *logicScint3 = new G4LogicalVolume(Scint3, scintMaterial, "Scint3");
  new G4PVPlacement(0, pos1, logicScint3, "Scint3", worldLV, false, 11, fCheckOverlaps);

  G4Tubs *Scint4 = new G4Tubs("Scint4", 25.15*cm, 35.15*cm, w, 216*deg, 72*deg);
  G4LogicalVolume *logicScint4 = new G4LogicalVolume(Scint4, scintMaterial, "Scint4");
  new G4PVPlacement(0, pos1, logicScint4, "Scint4", worldLV, false, 12, fCheckOverlaps);

  G4Tubs *Scint5 = new G4Tubs("Scint5", 25.15*cm, 35.15*cm, w, 288*deg, 72*deg);
  G4LogicalVolume *logicScint5 = new G4LogicalVolume(Scint5, scintMaterial, "Scint5");
  new G4PVPlacement(0, pos1, logicScint5, "Scint5", worldLV, false, 13, fCheckOverlaps);
  
  //previous 5 form an annulus, 6th scintillator goes on the back

  G4Tubs *Scint6 = new G4Tubs("Scint6", 0*cm, 35*cm, 4.7*cm, 0*deg, 360*deg);
  G4LogicalVolume *logicScint6 = new G4LogicalVolume(Scint6, scintMaterial, "Scint6");
  new G4PVPlacement(0, G4ThreeVector(0,0,205.45*cm), logicScint6, "Scint6", worldLV, false, 14, fCheckOverlaps);//186.45


  //Set colours
  auto CATScolour = new G4VisAttributes(G4Colour(1.0,1.0,0.0));
  CATScolour->SetVisibility(true);
  logicCore->SetVisAttributes(CATScolour);
  logicAnnulusPiece1->SetVisAttributes(CATScolour);
  logicAnnulusPiece2->SetVisAttributes(CATScolour);
  logicAnnulusPiece3->SetVisAttributes(CATScolour);
  logicAnnulusPiece4->SetVisAttributes(CATScolour);
  logicAnnulusPiece5->SetVisAttributes(CATScolour);
  logicAnnulusPiece6->SetVisAttributes(CATScolour);
  logicRing->SetVisAttributes(CATScolour);
  logicScint1->SetVisAttributes(CATScolour);
  logicScint2->SetVisAttributes(CATScolour);
  logicScint3->SetVisAttributes(CATScolour);
  logicScint4->SetVisAttributes(CATScolour);
  logicScint5->SetVisAttributes(CATScolour);
  logicScint6->SetVisAttributes(CATScolour);

  //Creating a colour for the target box
  auto target_colour = new G4VisAttributes(G4Colour(1.0, 0.65, 0.0));
  target_colour->SetVisibility(true);
  target_box_LV->SetVisAttributes(target_colour);



  //Next, we make the collimator

  G4double Leadx = 351.5*mm;
  G4double Longy = 50*mm;
  G4double Longzz = 650.5*mm;

  //Two of the Long Components
  G4Box *LongBit1 = new G4Box("LongBit1", Leadx+111*mm, Longy, Longzz);
  G4Box *LongBit2 = new G4Box("LongBit2", Leadx+111*mm, Longy, Longzz);

  G4Box* OtherLongBit1 = new G4Box("OtherLongBit1", Longy, Leadx+10*mm, Longzz);
  G4Box* OtherLongBit2 = new G4Box("OtherLongBit2", Longy, Leadx+10*mm, Longzz);


  G4Box* EndBit = new G4Box("EndBit", Leadx+110*mm, Leadx+105*mm, Longy);

  //subtraction solid here!
  G4Box* FrontBit = new G4Box("FrontBit", 460.5*mm, 460*mm, 105*mm);
  G4Tubs* FrontBitHole = new G4Tubs("FrontBitHole", 0*cm, 6.9*cm, 105.1*mm, 0*deg, 360*deg); //had to make the hole slightly longer than the box- otherwise you could not see the hole on both sides of the front bit

  G4SubtractionSolid *subtraction = new G4SubtractionSolid("subtraction", FrontBit, FrontBitHole);


  //endbit transform
  G4ThreeVector EndDisplacement = G4ThreeVector(0,0,66.15*cm);//adding 5cm to z so no overlap with back scintillator
  G4RotationMatrix none = G4RotationMatrix(); //for no rotation
  G4Transform3D EndBitTransform = G4Transform3D(none, EndDisplacement);


  G4double Placement = 401.5*mm;
  G4double LongBitZ= -1.3*cm;

  //LongBit1 transform
  G4ThreeVector HighLongBit1 = G4ThreeVector(0,Placement+1*cm,LongBitZ);
  G4Transform3D LongBit1Transform = G4Transform3D(none, HighLongBit1);

  //LongBit2 transform
  G4ThreeVector LowLongBit2 = G4ThreeVector(0,-Placement,LongBitZ);
  G4Transform3D LongBit2Transform = G4Transform3D(none, LowLongBit2);

  //OtherLongBit1 transform
  G4ThreeVector OLB1Displacement = G4ThreeVector(Placement+1*cm,0,LongBitZ);
  G4Transform3D OLB1Transform = G4Transform3D(none, OLB1Displacement);

  //OtherLongBit2 transform
  G4ThreeVector OLB2Displacement = G4ThreeVector(-Placement-1*cm,0,LongBitZ);
  G4Transform3D OLB2Transform = G4Transform3D(none, OLB2Displacement);

  //front
  G4ThreeVector FrontDisplacement = G4ThreeVector(1*mm,5*mm,-695.5*mm);
  G4Transform3D FrontBitTransform = G4Transform3D(none, FrontDisplacement);

  G4MultiUnion* LeadBox = new G4MultiUnion("LeadBox");

  LeadBox->AddNode(*EndBit, EndBitTransform);
  LeadBox->AddNode(*LongBit1, LongBit1Transform);
  LeadBox->AddNode(*LongBit2, LongBit2Transform);
  LeadBox->AddNode(*OtherLongBit1, OLB1Transform);
  LeadBox->AddNode(*OtherLongBit2, OLB2Transform);
  LeadBox->AddNode(*subtraction, FrontBitTransform);

  LeadBox->Voxelize();

  G4LogicalVolume *LeadBoxLogic = new G4LogicalVolume(LeadBox, boxMaterial, "LeadLogic");
  new G4PVPlacement(0, pos1, LeadBoxLogic, "PLeadBox", worldLV, 16, true, fCheckOverlaps);//add fCheckOverLaps


  //Colour collimator
  auto LeadBoxVisAtt= new G4VisAttributes(G4Colour(0.0,1.0,1.0));
  LeadBoxVisAtt->SetVisibility(true);
  LeadBoxLogic->SetVisAttributes(LeadBoxVisAtt);

				
  //Now we make the plastic veto for charged particles

  G4Box* Veto = new G4Box("Veto", 7*cm, 7*cm, 2.5*mm);
  G4LogicalVolume *VetoLogic = new G4LogicalVolume(Veto, scintMaterial, "VetoLogic");
  new G4PVPlacement(0, G4ThreeVector(0,5*mm, 693.5*mm), VetoLogic, "PVeto", worldLV, 17, true, fCheckOverlaps);
  //873.5

  auto VetoVisAtt= new G4VisAttributes(G4Colour(1.0,0.0,0.0));
  VetoVisAtt->SetVisibility(true);
  VetoLogic->SetVisAttributes(VetoVisAtt);


			     
  G4Cons* LeadCone = new G4Cons("LeadCone", 138*mm, 260*mm, 187*mm, 260*mm, 73*mm, 0*deg, 360*deg);
  G4LogicalVolume *LeadConeLogic = new G4LogicalVolume(LeadCone, boxMaterial, "LeadConeLogic");
  new G4PVPlacement(0, G4ThreeVector(0,0,1019.5*mm), LeadConeLogic, "PLeadCone", worldLV, 15, true, fCheckOverlaps);//G4ThreeVector(0,0,-390.5*mm), 1227.5, 1182.5
  //1109.5	
 
  auto LeadConeVisAtt= new G4VisAttributes(G4Colour(1.0,0.0,1.0));
  LeadConeVisAtt->SetVisibility(true);
  LeadConeLogic->SetVisAttributes(LeadConeVisAtt);				
				                                        
  // Visualization attributes
  //
  worldLV->SetVisAttributes (G4VisAttributes::GetInvisible());

  return worldPV;
}

  //Main Construct ends here!


  void B4cDetectorConstruction::ConstructSDandField()
{
  G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

  // 
  // Sensitive detectors
  //
  auto coreSD = new B4cCalorimeterSD("CoreSD", "CoreHitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(coreSD);		// consider making all of these the same sensitive detector, should increase mean energy of core
  SetSensitiveDetector("Core",coreSD);

  auto annuluspiece1SD = new B4cCalorimeterSD("AnnulusPiece1SD", "AnnulusPiece1HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece1SD);
  SetSensitiveDetector("AnnulusPiece1",annuluspiece1SD);

  auto annuluspiece2SD = new B4cCalorimeterSD("AnnulusPiece2SD", "AnnulusPiece2HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece2SD);
  SetSensitiveDetector("AnnulusPiece2",annuluspiece2SD);

  auto annuluspiece3SD = new B4cCalorimeterSD("AnnulusPiece3SD", "AnnulusPiece3HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece3SD);
  SetSensitiveDetector("AnnulusPiece3",annuluspiece3SD);

  auto annuluspiece4SD = new B4cCalorimeterSD("AnnulusPiece4SD", "AnnulusPiece4HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece4SD);
  SetSensitiveDetector("AnnulusPiece4",annuluspiece4SD);

  auto annuluspiece5SD = new B4cCalorimeterSD("AnnulusPiece5SD", "AnnulusPiece5HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece5SD);
  SetSensitiveDetector("AnnulusPiece5",annuluspiece5SD);

  auto annuluspiece6SD = new B4cCalorimeterSD("AnnulusPiece6SD", "AnnulusPiece6HitsCollection", 1);
  G4SDManager::GetSDMpointer()->AddNewDetector(annuluspiece6SD);
  SetSensitiveDetector("AnnulusPiece6",annuluspiece6SD);


}

