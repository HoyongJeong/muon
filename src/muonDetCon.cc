////////////////////////////////////////////////////////////////////////////////
//   muonDetCon.cc for Liz's 2018 winter project.                             //
//                                                                            //
//   Definitions of muonDetCon class's member functions.                      //
// And it describes geometry of simulation.                                   //
//                                                                            //
//                    - 10. Jan. 2017. Hoyong Jeong (hyjeong@hep.korea.ac.kr) //
////////////////////////////////////////////////////////////////////////////////

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"

#include "muonDetCon.hh"


//////////////////////////////////////////////////
//   Constructor and destructor                 //
//////////////////////////////////////////////////
muonDetCon::muonDetCon()
{
	ConstructMaterials();
	DefineDimensions();
}

muonDetCon::~muonDetCon()
{
	DestructMaterials();
}

//////////////////////////////////////////////////
//   Define dimensions                          //
//////////////////////////////////////////////////
void muonDetCon::DefineDimensions()
{
	// World dimensions
	// Laboratory size
	m_LabX = 2000.0 * mm; // World x dimension
	m_LabY = 2000.0 * mm; // World y dimension
	m_LabZ = 2000.0 * mm; // World z dimension
}


//////////////////////////////////////////////////
//   Construct everything                       //
//////////////////////////////////////////////////
G4VPhysicalVolume* muonDetCon::Construct()
{
	// World
	m_LabSolid = new G4Box("labSolid", m_LabX/2, m_LabY/2, m_LabZ/2);
	m_LabLV = new G4LogicalVolume(m_LabSolid, m_AirMat, "labLV");
	m_LabPV = new G4PVPlacement(0, G4ThreeVector(), "labPV", m_LabLV, 0, false, 0);

	return m_LabPV;
}

void muonDetCon::ConstructMaterials()
{
	const G4double labTemp = 300.0 * kelvin;

	// Elements to be used to construct materials
	m_ElH  = new G4Element( "Hydrogen",  "H",  1,   1.00794*g/mole);
	m_ElC  = new G4Element(   "Carbon",  "C",  6,  12.011  *g/mole);
	m_ElN  = new G4Element( "Nitrogen",  "N",  7,  14.00674*g/mole);
	m_ElO  = new G4Element(   "Oxygen",  "O",  8,  15.9994 *g/mole);
	m_ElF  = new G4Element( "Fluorine",  "F",  9,  18.9984 *g/mole);
	m_ElMg = new G4Element("Magnesium", "Mg", 12,  24.3050 *g/mole);
	m_ElAl = new G4Element( "Aluminum", "Al", 13,  26.98154*g/mole);
	m_ElSi = new G4Element(  "Silicon", "Si", 14,  28.0855 *g/mole);
	m_ElAr = new G4Element(    "Argon", "Ar", 18,  39.948  *g/mole);
	m_ElCr = new G4Element("Chromuium", "Cr", 24,  51.9961 *g/mole);
	m_ElFe = new G4Element(     "Iron", "Fe", 26,  55.845  *g/mole);
	m_ElNi = new G4Element(   "Nickel", "Ni", 28,  58.9634 *g/mole);
	m_ElCu = new G4Element(   "Copper", "Cu", 29,  63.546  *g/mole);
	m_ElZn = new G4Element(     "Zinc", "Zn", 30,  65.38   *g/mole);
	m_ElY  = new G4Element(  "Yttrium",  "Y", 39,  88.90585*g/mole);
	m_ElSn = new G4Element(      "Tin", "Sn", 50, 118.71   *g/mole);
	m_ElCe = new G4Element(   "Cerium", "Ce", 58, 140.116  *g/mole);
	m_ElLu = new G4Element( "Lutetium", "Lu", 71, 176.944  *g/mole);

	// Air material
	m_AirMat = new G4Material("Air", 1.1839e-3*g/cm3, 3, kStateGas, labTemp); // Density at 1 atm
	m_AirMat -> AddElement(m_ElN, 75.47/99.95);
	m_AirMat -> AddElement(m_ElO, 23.20/99.95);
	m_AirMat -> AddElement(m_ElAr, 1.28/99.95);

	// Plastic scintillator (counter) material
	m_CouMat = new G4Material("PlasticScint", 1.032*g/cm3, 2, kStateSolid, labTemp);
	m_CouMat -> AddElement(m_ElC, 10);
	m_CouMat -> AddElement(m_ElH, 11);

	// Vacuum material
	m_VacMat = new G4Material("Vacumm", 1.1839e-10*g/cm3, 3, kStateGas, labTemp);
	m_VacMat -> AddElement(m_ElN, 75.47/99.95);
	m_VacMat -> AddElement(m_ElO, 23.20/99.95);
	m_VacMat -> AddElement(m_ElAr, 1.28/99.95);
}

void muonDetCon::DestructMaterials()
{
	delete m_VacMat;
	delete m_CouMat;
	delete m_AirMat;

	delete m_ElLu;
	delete m_ElCe;
	delete m_ElSn;
	delete m_ElY;
	delete m_ElZn;
	delete m_ElCu;
	delete m_ElNi;
	delete m_ElFe;
	delete m_ElCr;
	delete m_ElAr;
	delete m_ElSi;
	delete m_ElAl;
	delete m_ElMg;
	delete m_ElF;
	delete m_ElO;
	delete m_ElN;
	delete m_ElC;
	delete m_ElH;
}
