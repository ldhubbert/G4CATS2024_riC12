//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file exampleB4c.cc
/// \brief Main program of the B4c example

#include "B4cDetectorConstruction.hh"
#include "B4cActionInitialization.hh"
#include "B4PrimaryGeneratorAction.hh"
#include "B4File.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "FTFP_BERT.hh"
#include "Randomize.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "TFile.h"
#include "TNtuple.h"

TFile *f = new TFile("~/EvGen/out/basic/g_300_0_0_in.root");
TNtuple *n = (TNtuple*)f->Get("h1");
const Int_t number_of_events = n->GetEntries();

bool hardcode = false;
G4String macro;

int main(int argc,char** argv)
{	
  
  //Setting up variables and initializations
  
//  G4String session;

//#ifdef G4MULTITHREADED
//  G4int nThreads = 0;
//#endif

  //Choose the Random engine
//  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  //Construct the default run manager
//#ifdef G4MULTITHREADED
//  G4MTRunManager * runManager = new G4MTRunManager;
//  if ( nThreads > 0)
//  {
//  runManager->SetNumberOfThreads(nThreads);
//  }
//#else
  G4RunManager * runManager = new G4RunManager;
//#endif

  //Set manadatory initialization classes
  auto detConstruction = new B4cDetectorConstruction();
  runManager->SetUserInitialization(detConstruction);

  auto physicsList = new FTFP_BERT;
  runManager->SetUserInitialization(physicsList);

  auto actionInitialization = new B4cActionInitialization();
  runManager->SetUserInitialization(actionInitialization);

  //Initialize visualization
//  auto visManager = new G4VisExecutive;
//  visManager->Initialize();

  //Get the pointer to the User Interface session
  auto UImanager = G4UImanager::GetUIpointer();

  //End of setting up variables and initializations
  //Start of defining how input into the terminal controls the simulation

  //this goes through the commands you have written in the command line
  //i.e., if you write ./build/exampleB4c -m run1.mac, the simulation is argument 0, "-m" is argument 1, and "run1.mac" is argument 2
  //However, I just want the loop to recognize the command, i.e., "-m", and don't care about what is written after that.
  //So, I will just go through the foor loop once.
  
  //for ( G4int i=0; i<argc; i=i+1 )
  for (G4int i = 1; i < 2; i++)
  {
    if ( G4String(argv[i]) == "-m" )
    {
    macro = argv[i+1]; 
    }
//    else if ( G4String(argv[i]) == "-u" )
//    {
//    session = argv[i+1];
//    }
    else if ( G4String(argv[i]) == "-h" )
    {
    hardcode = true;
    }

//#ifdef G4MULTITHREADED
//    else if ( G4String(argv[i]) == "-t" )
//    {
//    nThreads = G4UIcommand::ConvertToInt(argv[i+1]);
//    }
//#endif

  } 

  //Detect interactive mode (if no macro provided or hardcoded not specified) and define UI session
//  G4UIExecutive* ui = 0;
//  if ( (! macro.size()) && (hardcode != "true") )
//  {
//  ui = new G4UIExecutive(argc, argv, session);
//  }

  //Detect hard-coded material without UI session
  if ( hardcode )
  {
  runManager->Initialize();
  runManager->BeamOn(number_of_events);
  }

  //If not hardcode, process macro or start UI session
  else if ( macro.size() )
  {
  //batch mode
  G4String command = "/control/execute ";
  UImanager->ApplyCommand(command+macro);
  }
//  else 
//  {  
  //interactive mode: define UI session
//    UImanager->ApplyCommand("/control/execute init_vis.mac");
//    if (ui->IsGUI()) 
//    {
//    UImanager->ApplyCommand("/control/execute gui.mac");
//    }
//  ui->SessionStart();
//  delete ui;
//  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !

//  delete visManager;
  delete runManager;
}

