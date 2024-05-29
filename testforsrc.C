void testforsrc()
{
	TFile *f = new TFile("~/EvGen/out/5cm/compton_c_300_in.root");
	TNtuple *n = (TNtuple*)f->Get("h1");


	Float_t x_position[n->GetEntries()];
	Float_t y_position[n->GetEntries()];
	Float_t z_position[n->GetEntries()];

	for (Int_t row = 0; row < 3; row++)
	{

		n->GetEntry(row);

		x_position[row] = n->GetArgs()[0];
		y_position[row] = n->GetArgs()[1];
		z_position[row] = n->GetArgs()[2];

		cout << "ROW #: " << row << endl;
		cout << "X POSITION: " << x_position[row] << endl;
		cout << "Y POSITION: " << y_position[row] << endl;
		cout << "Z POSITION: " << z_position[row] << endl;

		ROOT::Math::XYZVectorF position(x_position[row], y_position[row], z_position[row]);

		cout << "POSITION VECTOR: " << position << endl;
	
	}

}
