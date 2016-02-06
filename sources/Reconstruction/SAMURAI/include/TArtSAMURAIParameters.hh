#ifndef _TARTNEBULAPARAMETERS_H_
#define _TARTNEBULAPARAMETERS_H_

#include <TNamed.h>
#include <TList.h>

#include <map>

class TXMLNode;
class TArtRIDFMap;
class TArtTacquilaMap;
class TArtStoreManager;
class TArtDCHitPara;
class TArtHODPlaPara;
class TArtRPTOFPlaPara;
class TArtTEDCsIPara;
class TArtNEBULAPlaPara;
class TArtNeuLANDPlaPara;
class TArtTacquilaPara;

typedef std::map<TArtRIDFMap, const TArtNEBULAPlaPara*> TArtNEBULAPlaParaMap;
typedef std::pair<TArtRIDFMap, const TArtNEBULAPlaPara*> TArtNEBULAPlaParaPair;
class TArtNEBULAHPCPara;
typedef std::map<TArtRIDFMap, const TArtNEBULAHPCPara*> TArtNEBULAHPCParaMap;
typedef std::pair<TArtRIDFMap, const TArtNEBULAHPCPara*> TArtNEBULAHPCParaPair;

typedef std::map<TArtTacquilaMap, const TArtNeuLANDPlaPara*> TArtNeuLANDPlaParaMap;
typedef std::pair<TArtTacquilaMap, const TArtNeuLANDPlaPara*> TArtNeuLANDPlaParaPair;
typedef std::map<TArtTacquilaMap, const TArtTacquilaPara*> TArtTacquilaParaMap;
typedef std::pair<TArtTacquilaMap, const TArtTacquilaPara*> TArtTacquilaParaPair;

class TArtSAMURAIParameters : public TNamed
{
public: 
  TArtSAMURAIParameters(const char* name = "SAMURAIParameters", 
		       const char* title = "SAMURAIParameters");
  ~TArtSAMURAIParameters();

  // singleton. If you want to use multiple set of parameters, use norminal way.
  static TArtSAMURAIParameters* Instance(const char* name = "SAMURAIParameters", 
					 const char* title = "SAMURAIParameters");
  static void Delete();

  Bool_t LoadParameter(const char *xmlfile);
  Bool_t LoadNeuLANDTCal(const char *csvfile);
  Bool_t LoadTCal(const char *cfile){return LoadNeuLANDTCal(cfile);}

  void PrintListOfHODPlaPara ();
  void PrintListOfRPTOFPlaPara ();
  void PrintListOfTEDCsIPara ();
  void PrintListOfBPCHitPara ();
  void PrintListOfBDC1HitPara();
  void PrintListOfBDC2HitPara();
  void PrintListOfFDC1HitPara();
  void PrintListOfFDC2HitPara();
  void PrintListOfRPDCHitPara();
  void PrintListOfNEBULAPlaPara() const;
  void PrintListOfNeuLANDPlaPara() const;
  void PrintListOfNeuLANDVETOPlaPara() const;
  //  void PrintListOfTacquilaPara() const;

  TList* GetListOfHODPlaPara () {return listOfHODPlaPara; }
  TList* GetListOfRPTOFPlaPara () {return listOfRPTOFPlaPara; }
  TList* GetListOfTEDCsIPara () {return listOfTEDCsIPara; }
  TList* GetListOfBPCHitPara () {return listOfBPCHitPara; }
  TList* GetListOfBDC1HitPara() {return listOfBDC1HitPara; }
  TList* GetListOfBDC2HitPara() {return listOfBDC2HitPara; }
  TList* GetListOfFDC1HitPara() {return listOfFDC1HitPara; }
  TList* GetListOfFDC2HitPara() {return listOfFDC2HitPara; }
  TList* GetListOfRPDCHitPara() {return listOfBDC1HitPara; }

  const TArtHODPlaPara* FindHODPlaPara   (TArtRIDFMap *rmap) const;
  const TArtRPTOFPlaPara* FindRPTOFPlaPara   (TArtRIDFMap *rmap) const;
  const TArtTEDCsIPara* FindTEDCsIPara   (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindBPCHitPara   (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindBDC1HitPara  (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindBDC2HitPara  (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindFDC1HitPara  (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindFDC2HitPara  (TArtRIDFMap *rmap) const;
  const TArtDCHitPara * FindRPDCHitPara  (TArtRIDFMap *rmap) const;

  const TArtNEBULAPlaPara* FindNEBULAPlaUPara(const TArtRIDFMap &rmap) const;
  const TArtNEBULAPlaPara* FindNEBULAPlaDPara(const TArtRIDFMap &rmap) const;
  const TArtNEBULAPlaPara* FindNEBULAPlaPara(Int_t id) const;//find by id

  const TArtNEBULAHPCPara* FindNEBULAHPCPara(const TArtRIDFMap &rmap) const;
  const TArtNEBULAHPCPara* FindNEBULAHPCPara(Int_t id) const;//find by id

  const TArtNeuLANDPlaPara* FindNeuLANDPlaPara(const TArtTacquilaMap *rmap) const;
  const TArtNeuLANDPlaPara* FindNeuLANDPlaPara(Int_t id) const;//find by id

  const TArtTacquilaPara* FindTacquilaPara(const TArtTacquilaMap *rmap) const;
  const TArtTacquilaPara* FindTacquilaPara(Int_t id) const;//find by id
  const TArtNEBULAPlaPara* FindNeuLANDVETOPlaUPara(const TArtRIDFMap &rmap) const;
  const TArtNEBULAPlaPara* FindNeuLANDVETOPlaDPara(const TArtRIDFMap &rmap) const;
  const TArtNEBULAPlaPara* FindNeuLANDVETOPlaPara(Int_t id) const;//find by id

private:
  void ParseParaList(TXMLNode* node);
  TArtDCHitPara* ParseDCHitPara(TXMLNode* node, std::map<TArtRIDFMap, TArtDCHitPara *> * map);
  TArtHODPlaPara*    ParseHODPlaPara(TXMLNode* node);
  TArtRPTOFPlaPara*  ParseRPTOFPlaPara(TXMLNode* node);
  TArtTEDCsIPara*    ParseTEDCsIPara(TXMLNode* node);
  TArtNEBULAPlaPara* ParseNEBULAPlaPara(TXMLNode* node);
  TArtNEBULAHPCPara* ParseNEBULAHPCPara(TXMLNode* node);
  TArtNeuLANDPlaPara* ParseNeuLANDPlaPara(TXMLNode* node);
  TArtTacquilaPara*  ParseTacquilaPara(TXMLNode* node);
  TArtNEBULAPlaPara* ParseNeuLANDVETOPlaPara(TXMLNode* node);

  std::map<TArtRIDFMap, TArtHODPlaPara *> hod_pmap;
  std::map<TArtRIDFMap, TArtRPTOFPlaPara *> rptof_pmap;
  std::map<TArtRIDFMap, TArtTEDCsIPara *> ted_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> bpc_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> bdc1_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> bdc2_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> fdc1_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> fdc2_pmap;
  std::map<TArtRIDFMap, TArtDCHitPara *> rpdc_pmap;

  TArtNEBULAPlaParaMap  *fNEBULAPlaUParaMap, *fNEBULAPlaDParaMap;
  TArtNEBULAHPCParaMap  *fNEBULAHPCParaMap;
  TArtNeuLANDPlaParaMap *fNeuLANDPlaParaMap;
  TArtTacquilaParaMap   *fTacquilaParaMap;
  TArtNEBULAPlaParaMap  *fNeuLANDVETOPlaUParaMap, *fNeuLANDVETOPlaDParaMap;

  // list of parameters 
  TList *listOfHODPlaPara;
  TList *listOfRPTOFPlaPara;
  TList *listOfTEDCsIPara;
  TList *listOfBPCHitPara;
  TList *listOfBDC1HitPara;
  TList *listOfBDC2HitPara;
  TList *listOfFDC1HitPara;
  TList *listOfFDC2HitPara;
  TList *listOfRPDCHitPara;

  // for optimization
  std::map<int, TArtNEBULAPlaPara*> fIDNEBULAPlaParaMap;
  std::map<int, TArtNEBULAHPCPara*> fIDNEBULAHPCParaMap;
  std::map<int, TArtNeuLANDPlaPara*> fIDNeuLANDPlaParaMap;
  std::map<int, TArtTacquilaPara*> fIDTacquilaParaMap;
  std::map<int, TArtNEBULAPlaPara*> fIDNeuLANDVETOPlaParaMap;

  TArtStoreManager* fStoreManager;
  static TArtSAMURAIParameters* fSAMURAIParameters;

  ClassDef(TArtSAMURAIParameters,1);
};

#endif
