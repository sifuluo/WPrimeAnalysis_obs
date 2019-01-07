#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "analyzer.cc"
#include "tools.cc"

#include <TROOT.h>
#include <TString.h>
#include <TVector2.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile2D.h>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <TProfile.h>
#include <TEfficiency.h>
#include <string>

using namespace std;

void wprime() {
  // gSystem->Load("libDelphes");
  vector<TString> samplebasepaths;
  samplebasepaths.push_back("/fdata/hepx/store/user/aoverton0342/madGraph/");

  vector<TString> folders;
  folders.push_back("TDual_FormerLeptonic/");
  // folders.push_back("TDual_LatterLeptonic/");

  TString savepath = "/fdata/hepx/store/user/siluo/wprime/results/";
  TString savename = "TDualOptimized";

  Analyzer *a = new Analyzer(samplebasepaths,folders,30);
  a->SetOutput(savepath,savename);
  a->GetProbability(false);
  ofstream &logfile = a->logfile;
  // TFile* PFile= a->PFile;
  bool debug = false;
  if (debug) {
    a->SetStartEntry(0);
    a->ProcessEntries(100);
  }
  // int zeromassevt[] = {9, 23,29, 32,33,59,76,81,87};
  // TH2F* HadWdRdM = new TH2F("HadWdRdM","HadWdRdM",50,0.,5.,100,-50.,50.);
  // TH2F* HadTdRdM = new TH2F("HadTdRdM","HadTdRdM",50,0.,5.,100,-50.,50.);
  // TH2F* LepWdRdM = new TH2F("LepWdRdM","LepWdRdM",50,0.,5.,100,-50.,50.);
  // TH2F* LepTdRdM = new TH2F("LepTdRdM","LepTdRdM",50,0.,5.,100,-50.,50.);
  // TH1F* LepWM    = new TH1F("LepWM","LepWM",10,80.,81.);
  // TH1F* WPMass   = new TH1F("WPMass","WPMass",1200,0.,1200.);
  // TH1F* JetMatchTest = new TH1F("JetMatchMaxDeltaR","JetMatchDeltaR",40,0,4.);
  TH1F* WPMass = new TH1F("WPMass","WPrime Mass", 2000, 0, 2000);
  //When not goot match is achieved in GenLevel
  TH1F* WPMass0CNM = new TH1F("WPMass0CNM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass1CNM = new TH1F("WPMass1CNM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass2CNM = new TH1F("WPMass2CNM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass3CNM = new TH1F("WPMass3CNM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass4CNM = new TH1F("WPMass4CNM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass5CNM = new TH1F("WPMass5CNM","WPrime Mass", 2000, 0, 2000);
  //When good match is achieved in GenLevel
  TH1F* WPMass0CM = new TH1F("WPMass0CM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass1CM = new TH1F("WPMass1CM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass2CM = new TH1F("WPMass2CM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass3CM = new TH1F("WPMass3CM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass4CM = new TH1F("WPMass4CM","WPrime Mass", 2000, 0, 2000);
  TH1F* WPMass5CM = new TH1F("WPMass5CM","WPrime Mass", 2000, 0, 2000);
  // TH1F* WPMassWeight = new TH1F("WPMassWeight","WPrime Mass With Weight", 1000,0,1000);
  // Long64_t StartEntry = a->GetStartEntry();
  // Long64_t EndEntry = a->GetEndEntry();
  int npassentry, passentry, allentry;
  npassentry = 0;
  passentry = 0;
  allentry = 0;

  for (Int_t entry = a->GetStartEntry(); entry < a->GetEndEntry(); ++entry){
    // if (entry != 9) continue;
    if (a->ReadEvent(entry,debug) == -1) continue ;
    a->AssignGenParticles();

    // vector<TLorentzVector> scaledjets;
    // TLorentzVector neutrino;
    // TLorentzVector WPrime;
    // double bestp = a->Optimize(scaledjets, neutrino, WPrime);
    // if (bestp != 0) {
    //   WPMass->Fill(WPrime.M());
    //   WPMassWeight->Fill(WPrime.M(),bestp);
    // }

    //interfaces
    // vector<GenParticle*> &GenParticles = a->GenParticles;
    // vector<int> &GenWP = a->GenWP;
    // vector<int> &GenT = a->GenT;
    // vector<int> &GenB = a->GenB;
    // vector<int> &GenW = a->GenW;
    // vector<int> &GenOut = a->GenOut;
    // vector<int> &GenE = a->GenE;
    // vector<int> &GenMu = a->GenMu;
    // vector<Electron*> &Electrons = a->Electrons;
    // vector<Muon*> &Muons = a->Muons;
    // vector<Jet*> &AllJets = a->AllJets;
    // vector<Jet*> &Jets = a->Jets;
    // vector<Jet*> &BJets = a->BJets;
    // vector<Jet*> &NBJets = a->NBJets;
    // vector<TLorentzVector> LVAllJets = a->LVAllJets;
    // vector<TLorentzVector> LVJets = a->LVJets;
    // vector<bool> BTags = a->BTags;
    // vector<TLorentzVector> LVNBJets = a->LVNBJets;
    // vector<TLorentzVector> LVBJets = a->LVBJets;
    // vector<TLorentzVector> LVLeptons = a->LVLeptons;
    // vector<TLorentzVector> LVElectrons = a->LVElectrons;
    // vector<TLorentzVector> LVMuons = a->LVMuons;

    // TLorentzVector LVGenW = GenParticles[a->GenOtW]->P4();
    // TLorentzVector LVGenLep = GenParticles[a->GenLep]->P4();
    // TLorentzVector LVGenNeu = GenParticles[a->GenNeu]->P4();

    // cout <<Form("GenW: %5.1f(%5.1f, %5.1f, %5.1f, %5.1f)",LVGenW.M(),LVGenW.X(),LVGenW.Y(),LVGenW.Z(),LVGenW.T())<<endl;
    // cout <<Form( "GenLep (%5.1f, %5.1f, %5.1f, %5.1f); GenNeu (%5.1f, %5.1f, %5.1f, %5.1f)",LVGenLep.X(),LVGenLep.Y(),LVGenLep.Z(),LVGenLep.T(),LVGenNeu.X(),LVGenNeu.Y(),LVGenNeu.Z(),LVGenNeu.T() )<<endl;
    // a->PrintGenParticles("1");


    // if ((a->GenWPTWJ).size() != 2) {cout <<  Form("GenWPTWJ size %d, of Entry: %d, GenWPTW: %d, GenWPTWJ",(int) (a->GenWPTWJ).size(), entry, a->GenWPTW)<<endl;continue;}
    vector<int> BestPerm;
    vector<TLorentzVector> scaledjets;
    TLorentzVector neutrino, WPrime;
    allentry++;
    if (a->Optimize(BestPerm, scaledjets, neutrino, WPrime) == -1){
      npassentry++;
      continue;
    }
    double wpmass = WPrime.M();
    passentry++;
    WPMass->Fill(WPrime.M());
    int CorrectionPick = 0;
    vector<TLorentzVector> BestMatchJets = a->LVJetSort;
    double MaxDeltaR = a->OutJetMatchDeltaR;
    if (scaledjets.size() != BestMatchJets.size()) cout << "ScaledJets Size incorrect!!!" <<endl;
    for (unsigned ijet = 0; ijet < BestMatchJets.size(); ++ijet) {
      if ( (scaledjets[ijet].DeltaR(BestMatchJets[ijet])) <= 0.2  ) CorrectionPick++;
    }
    if (MaxDeltaR <= 0.2) {
      if (CorrectionPick == 0) WPMass0CM->Fill(wpmass);
      else if (CorrectionPick == 1) WPMass1CM->Fill(wpmass);
      else if (CorrectionPick == 2) WPMass2CM->Fill(wpmass);
      else if (CorrectionPick == 3) WPMass3CM->Fill(wpmass);
      else if (CorrectionPick == 4) WPMass4CM->Fill(wpmass);
      else if (CorrectionPick == 5) WPMass5CM->Fill(wpmass);
    }
    if (MaxDeltaR > 0.2)  {
      if (CorrectionPick == 0) WPMass0CNM->Fill(wpmass);
      else if (CorrectionPick == 1) WPMass1CNM->Fill(wpmass);
      else if (CorrectionPick == 2) WPMass2CNM->Fill(wpmass);
      else if (CorrectionPick == 3) WPMass3CNM->Fill(wpmass);
      else if (CorrectionPick == 4) WPMass4CNM->Fill(wpmass);
      else if (CorrectionPick == 5) WPMass5CNM->Fill(wpmass);
    }

    // if (entry < 100 && WPrime.M() == 0) cout << "Zero Mass:" <<entry << endl;


  }//Looped over all entries
  a->SaveOutput();
  logfile << Form("AllEntry: %i, Filled Entry: %i, Not Filled Entry: %i",allentry, passentry, npassentry) <<endl;
}
