////////////////////////////////////////////////////////////////////////////////
//   muonActIni.cc for Liz's 2018 winter project.                             //
//                                                                            //
//   Definitions of muonActIni class's member functions.                      //
// All actions must be initialized here in order to use multi thread.         //
// Currently we only have primary generator action. But you will add your own //
// user actions someday.                                                      //
//                                                                            //
//                    - 10. Jan. 2018. Hoyong Jeong (hyjeong@hep.korea.ac.kr) //
////////////////////////////////////////////////////////////////////////////////

#include "muonActIni.hh"
#include "muonPriGenAct.hh"

muonActIni::muonActIni() : G4VUserActionInitialization()
{
}

muonActIni::~muonActIni()
{
}

void muonActIni::BuildForMaster() const
{
}

void muonActIni::Build() const
{
	SetUserAction(new muonPriGenAct());
}  
