// && NpoleTarget Header file %% //

// Created: William Tireman - December 2014


#ifndef Npol_Target_h
#define Npol_Target_h

#include "G4SystemOfUnits.hh"

#include "NpolSubDetector.hh"

class G4LogicalVolume;
class G4AssemblyVolume;
class G4VPhysicalVolume;

class NpolTarget : public NpolSubDetector {
  
public:
  NpolTarget();
  ~NpolTarget();
  
  void ConstructTargetCan();
  void ConstructTargetFluid();
  virtual G4VPhysicalVolume *Construct(G4LogicalVolume *motherLV);
 
private: 
  G4LogicalVolume *TargetCanLV;
  G4LogicalVolume *TargetFluidLV;
};

#endif

