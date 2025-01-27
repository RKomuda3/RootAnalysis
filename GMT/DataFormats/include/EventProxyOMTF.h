#ifndef EVENTPROXYOMTF_h
#define EVENTPROXYOMTF_h

#include <string>
#include <typeinfo>
#include <vector>
#include "boost/shared_ptr.hpp"

#include "EventProxyBase.h"
#include "EventObj.h"
#include "GenObjColl.h"
#include "L1ObjColl.h"
#include "L1PhaseIIObjColl.h"
#include "MuonObjColl.h"
#include "TBranch.h"

struct OMTFHit{
  
public:
  
  int iPhi, iLayer, iHit, iQuality;
  
};

std::ostream& operator<< (std::ostream& stream, const OMTFHit& aHit); 


   class EventProxyOMTF: public EventProxyBase{

   public:

      EventProxyOMTF();
      virtual ~EventProxyOMTF();

      void init(std::vector<std::string> const& iFileNames);

      virtual EventProxyBase* clone() const;

     const EventObj  *getEventId() const {return myEvent;};

     const GenObjColl *getGenObjColl() const {return myGenObjColl;};

     const L1ObjColl  *getL1ObjColl() const { return myL1ObjColl;};

     const L1PhaseIIObjColl  *getL1PhaseIIObjColl() const { return myL1PhaseIIObjColl;};

     const MuonObjColl *getRecoMuonObjColl() const { return mymuonColl;}; 
     std::vector<OMTFHit> getHits() const;
     
   private:
     
     // Declaration of leaf types
     EventObj       *myEvent;
     GenObjColl     *myGenObjColl;
     L1ObjColl      *myL1ObjColl;
     L1PhaseIIObjColl *myL1PhaseIIObjColl;
     MuonObjColl *mymuonColl;
     std::vector<int> *hits;
     std::vector<int> *hitsQuality;
     

};
#endif
