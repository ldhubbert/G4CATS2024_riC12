void H100MeV()
{
	TCanvas *c1 = new TCanvas("c1", "", 20, 20, 1000, 1000);
	c1->Divide(1,1);
	c1->cd(1);
	
	TString filename = "~/G4CATS2024_rootinput/RUN_RESULTS.root";
	TFile *f = TFile::Open(filename);

	TH1F *h1 = new TH1F("Histogram Statistics", "", 500, 280, 310);

	//We define "r1" as the information pulled from tree "B4" in the file "~/G4CATS2024_rootinput/RUN_RESULTS.root"
	TTreeReader r1("B4", f);
	TTreeReaderValue<Double_t> Ecore(r1, "Ecore");
	TTreeReaderValue<Double_t> Eann1(r1, "Eann1");
	TTreeReaderValue<Double_t> Eann2(r1, "Eann2");
	TTreeReaderValue<Double_t> Eann3(r1, "Eann3");
	TTreeReaderValue<Double_t> Eann4(r1, "Eann4");
	TTreeReaderValue<Double_t> Eann5(r1, "Eann5");
	TTreeReaderValue<Double_t> Eann6(r1, "Eann6");

	//We define a while loop to extract data from each part of the CATS detector (the core and the 6 annuli)
	//This while loop filters through each event (from the first entry to the 10Kth entry) based on how TTreeReader and TTreeReaderValue work
	//We read the energy deposited into each CATS crystal for each event, sum them, and then that number is entered into the final histogram as a hit registered with that much total energy
	//For example, if the first particle enters CATS and sets off the core with 100MeV, but 0MeV everywhere else, the simulation registered a 100MeV particle. The final histogram will add 1 hit to the 100MeV bin.
	while (r1.Next())
	{
		h1->Fill((*Ecore + *Eann1 + *Eann2 + *Eann3 + *Eann4 + *Eann5 + *Eann6)*(1000));
	}

	h1->GetXaxis()->SetTitle("Energy (in MeV)");
	h1->GetYaxis()->SetTitle("Counts");
	h1->GetXaxis()->CenterTitle();
	h1->GetYaxis()->CenterTitle();
	h1->SetTitle("300MeV Beam Shot into CATS by EvGenBasic");
	h1->Draw();
}
