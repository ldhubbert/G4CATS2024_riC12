void ReturnArray()
{

	TFile *f = new TFile("~/EvGen/out/5cm/compton_c_300_in.root");
	TNtuple *n = (TNtuple*)f->Get("h1");

	Float_t x_position[n->GetEntries()];

	for (Int_t row = 0; /*row < n->GetEntries()*/ row < 3; row ++)
	{

		n->GetEntry(row);
		x_position[row] = n->GetArgs()[0];
		cout << x_position[row] << endl;

	}

	

}

//void test()
//{

//	Float_t *x_position = ReturnArray();

//	for (Int_t a = 0; a < 3; a++)
//	{

//		cout << x_position[a] << endl;

//	}	

//}
