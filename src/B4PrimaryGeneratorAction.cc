/// \file B4PrimaryGeneratorAction.cc
/// \brief Implementation of the B4PrimaryGeneratorAction class

#include "B4PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "TLorentzVector.h"
#include "TFile.h"
#include "G4ThreeVector.hh"
#include "TNtuple.h"

B4PrimaryGeneratorAction::B4PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction(),
   fParticleGun(nullptr)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  // default particle kinematic
  //
/*  auto particleDefinition 
    = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
  fParticleGun->SetParticleDefinition(particleDefinition);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(500.*MeV);

*/
}

B4PrimaryGeneratorAction::~B4PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void B4PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // This function is called at the begining of event

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get world volume 
  // from G4LogicalVolumeStore
  //
  G4double worldZHalfLength = 0.;//was 0
  auto worldLV = G4LogicalVolumeStore::GetInstance()->GetVolume("World");

  // Check that the world volume has box shape
  G4Box* worldBox = nullptr;
  if (  worldLV ) {
    worldBox = dynamic_cast<G4Box*>(worldLV->GetSolid());
  }

  if ( worldBox ) {
    worldZHalfLength = worldBox->GetZHalfLength();
  }
  else  {
    G4ExceptionDescription msg;
    msg << "World volume of box shape not found." << G4endl;
    msg << "Perhaps you have changed geometry." << G4endl;
    msg << "The gun will be place in the center.";
    G4Exception("B4PrimaryGeneratorAction::GeneratePrimaries()",
      "MyCode0002", JustWarning, msg);
  } 
  
  // Set gun position
  //fParticleGun->SetParticlePosition(G4ThreeVector(4*cm, 0., -worldZHalfLength));//-worldZHalfLength
  //fParticleGun->SetParticlePosition(G4ThreeVector(0*cm, 0., 0.));

  //fParticleGun->GeneratePrimaryVertex(anEvent);
  
  

  TFile *f = new TFile("~/EvGen/out/5cm/compton_c_300_in.root");
  TNtuple *n = (TNtuple*)f->Get("h1");

  //Where, in our TNtuple, each row corresponds to an event, and each column represents a different variable
  //For Compton scattering off of C12, those columns are:
  //
  //0-2: interaction vertex positions
  //3-7: incident photon beam
  //8-12: recoil nucleus
  //13-17: scattered particle
  //
  //Column 0: Interaction x-vertex position --- X_vtx
  //Column 1: Interaction y-vertex position --- Y_vtx
  //Column 2: Interaction z-vertex position --- Z_vtx
  //Column 3: x-momentum of incoming photon beam (direction cosine) --- Px_bm
  //Column 4: y-momentum of incoming photon beam (direction cosine) --- Py_bm
  //Column 5: z-momentum of incoming photon beam (direction cosine) --- Pz_bm
  //NOTE: In the EvGen code, columns 6 and 7 are equal due to photon beam properties.
  //Column 6: total incident photon beam momentum --- Pt_bm
  //COlumn 7: incident photon beam energy (using Bremsstrahlung dist.) --- En_bm
  //Column 8: x-momentum of recoil nucleus --- Px_l0167 (the letter "l" is in front; that's not a one)
  //Column 9: y-momentum of recoil nucleus --- Py_l0167
  //Column 10: z-momentum of recoil nucleus --- Pz_l0167
  //Column 11: total recoil nucleus momentum --- Pt_l0167
  //Column 12: energy of recoil nucleus --- En_l0167
  //Column 13: x-momentum of scattered particle --- Px_l0201
  //Column 14: y-momentum of scattered particle --- Py_l0201
  //Column 15: z-momentum of scattered particle --- Pz_l0201
  //Column 16: total scattered particle momentum --- Pt_l0201
  //Column 17: energy of scattered particle --- En_l0201
  //For a total of 18 columns.
  //
  //Direction cosines need to be multiplied by the total momentum in order to get the momentum in that direction.
  //Direction cosines are numbers between -1 and 1.
  //
  //We only want columns 0, 1, 2, 13, 14, 15, 16, 17
  
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particleDefinition = particleTable->FindParticle("gamma");

  fParticleGun->SetParticleDefinition(particleDefinition);

  Float_t x_position[n->GetEntries()];
  Float_t y_position[n->GetEntries()];
  Float_t z_position[n->GetEntries()];

  for (Int_t row = 0; row < n->GetEntries(); row++)
  {
	//loads the row data
  	n->GetEntry(row);

	x_position[row] = n->GetArgs()[0];
	y_position[row] = n->GetArgs()[1];
	z_position[row] = n->GetArgs()[2];

	//cout << "ROW #: " << row << endl;
	//cout << "X POSITION: " << x_position[row] << endl;
	//cout << "Y POSITION: " << y_position[row] << endl;
	//cout << "Z POSITION: " << z_position[row] << endl;

	Float_t scattered_t_mom = n->GetArgs()[16];
	fParticleGun->SetParticleMomentum(scattered_t_mom);

	Float_t scattered_energy = n->GetArgs()[17];
	fParticleGun->SetParticleEnergy(scattered_energy);

	G4ThreeVector position(x_position[row], y_position[row], z_position[row]);
	fParticleGun->SetParticlePosition(position);

	//Produce event
	fParticleGun->GeneratePrimaryVertex(anEvent);
	

  }


}


