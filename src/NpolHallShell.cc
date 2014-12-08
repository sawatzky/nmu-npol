//********************************************************************
//* License and Disclaimer: From GEANT Collaboration                 *
//*                                                                  *
//* The  Geant4 software  is  copyright of the Copyright Holders  of *
//* the Geant4 Collaboration.  It is provided  under  the terms  and *
//* conditions of the Geant4 Software License,  included in the file *
//* LICENSE and available at  http://cern.ch/geant4/license .  These *
//* include a list of copyright holders.     		      	*
//********************************************************************
//* The Geant4 software is used by the Northern Michigan University  *
//* in accordance to the Geant4 software license specified above.    *
//* The NMU Collaboration does not hold any rights to this software  *
//* and gives full permission for its use to others under the limits *
//* imposed by the GEANT4 Collaboration.  The NMU Collaboration      *
//* gives no express or implied warranty and use of our code is at   *
//* the users discretion only.  		    			*
//********************************************************************

#include "G4PhysicalConstants.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4AssemblyVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4ios.hh"

#include "NpolMaterials.hh"
#include "NpolHallShell.hh"

NpolHallShell::NpolHallShell() {
  G4cout << "Initializing Hall Shell: Wall, floor, roof" << G4endl;
}

NpolHallShell::~NpolHallShell() {
  G4cout << "Deleting Hall Shell: Wall, floor, roof" << G4endl;
}

// Construct the Hall Wall in the world
void NpolHallShell::ConstructHallShellWall(G4LogicalVolume *motherLV) {
  G4ThreeVector Ta;
  G4RotationMatrix Ra; 
  // Rotation of assembly inside the world 
  Ra.rotateX(+90.0*deg);
  Ra.rotateY(0.0*deg);
  Ra.rotateZ(0.0*deg);
  Ta.setX(0.0*m); Ta.setY(0.0*m); Ta.setZ(0.0*m);
  G4Transform3D Tr = G4Transform3D(Ra,Ta);

  G4Tubs *HallShellWall = new G4Tubs("HallShellWall",22.860*m, 23.7744*m, 
	   15.0*m, 0.0*deg, 360.*deg);
  HallShellWallLV = new G4LogicalVolume(HallShellWall,
           NpolMaterials::GetInstance()->GetConcrete(),"HallShellWallLV",0,0,0);
  new G4PVPlacement(Tr, HallShellWallLV,"HallShellWall", motherLV, false, 0);
  //G4VisAttributes *TopVisAtt= new G4VisAttributes(G4Colour(2.0,1.0,0.0));
  //HallShellWallLV->SetVisAttributes(TopVisAtt);
  HallShellWallLV->SetVisAttributes(G4VisAttributes::GetInvisible());
}

// Construct the Hall Floor in the world
void NpolHallShell::ConstructHallShellFloor(G4LogicalVolume *motherLV) {
  
  G4ThreeVector Ta;
  G4RotationMatrix Ra; 
  // Rotation of assembly inside the world 
  Ra.rotateX(-90.0*deg);
  Ra.rotateY(0.0*deg);
  Ra.rotateZ(0.0*deg);
  Ta.setX(0.0*m); Ta.setY(-16.0*m); Ta.setZ(0.0*m);
  G4Transform3D Tr = G4Transform3D(Ra,Ta);

  G4Tubs *HallShellFloor = new G4Tubs("HallShellFloor",0.0*m, 23.7744*m, 
	  1.0*m, 0.0*deg, 360.*deg);
  HallShellFloorLV = new G4LogicalVolume(HallShellFloor,
	  NpolMaterials::GetInstance()->GetConcrete(),"HallShellFluiLV",0,0,0);
  new G4PVPlacement(Tr, HallShellFloorLV,"HallShellFloor", motherLV, false, 0);
  //G4VisAttributes *TopVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  //HallShellFloorLV->SetVisAttributes(TopVisAtt);
  HallShellFloorLV->SetVisAttributes(G4VisAttributes::GetInvisible());
}

// Construct the Hall Roof in the world
void NpolHallShell::ConstructHallShellRoof(G4LogicalVolume *motherLV) {

  G4ThreeVector Ta;
  G4RotationMatrix Ra; 
  // Rotation of assembly inside the world 
  Ra.rotateX(-90.0*deg);
  Ra.rotateY(0.0*deg);
  Ra.rotateZ(0.0*deg);
  Ta.setX(0.0*m); Ta.setY(-17.0*m); Ta.setZ(0.0*m);
  G4Transform3D Tr = G4Transform3D(Ra,Ta);

  G4Sphere *HallShellRoof = new G4Sphere("HallShellRoof",40.0*m, 41.0*m, 0.0*deg, 360.0*deg, 0.0*deg, 37.0*deg);
  HallShellRoofLV = new G4LogicalVolume(HallShellRoof,
          NpolMaterials::GetInstance()->GetConcrete(),"HallShellFluiLV",0,0,0);
  new G4PVPlacement(Tr, HallShellRoofLV,"HallShellRoof", motherLV, false, 0);
  // G4VisAttributes *TopVisAtt= new G4VisAttributes(G4Colour(0.0,1.0,2.0));
  //HallShellRoofLV->SetVisAttributes(TopVisAtt);
  HallShellRoofLV->SetVisAttributes(G4VisAttributes::GetInvisible());
}

void NpolHallShell::Construct(G4LogicalVolume *motherLV) {
  
  ConstructHallShellWall(motherLV);
  ConstructHallShellFloor(motherLV);
  ConstructHallShellRoof(motherLV);
}

