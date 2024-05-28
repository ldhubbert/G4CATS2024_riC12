//To see if we can extract the number of entries from the TNtuple:
void Openh1()
{

	TFile *f = new TFile("~/EvGen/out/5cm/compton_c_300_in.root");
	//Typecasts "h1" as a TNtuple. The star in "TNtuple*" means that "n" will be a pointer to "h1" in file "f" ("Get" returns a pointer.)
	//So, I'm thinking that a star on the first TNtuple requires a star on the second TNtuple.
	//i.e., could have written the beginning as "TNtuple* n".
	TNtuple *n = (TNtuple*)f->Get("h1");

	//Typecasts the number of entries as an integer
	Int_t entries = (Int_t)n->GetEntries();
	cout << "Number of Entries: " << entries << endl;

	//Prints out all the rows and columns of the TNtuple. Here, you can see all the data stored in the TNtuple visually!
	n->Scan();

	Int_t columns = (Int_t)n->GetNvar();
	cout << "Number of Columns: " << columns << endl;

}

//Correctly outs the number of entries in h1 (100 000)!
//Correctly outs the number of columns in h1, for Compton Scattering off of C12 (18)!

//To see if we can extract data from the TNtuple:
void extract_data()
{

	TFile *f = new TFile("~/EvGen/out/5cm/compton_c_300_in.root");
	TNtuple *n = (TNtuple*)f->Get("h1");

	for (Int_t row = 0; /*row < n->GetEntries()*/ row < 1; row++)
	{
		cout << "lol" << endl;
		n->GetEntry(row);

		for (Int_t column = 0; column < n->GetNvar(); column++)
		{
			
			//retrieves the value of the variable at the current column index
			Float_t value = n->GetArgs()[column];

			cout << "Column " << column << " Value: " << value << endl;

		}

	}
	
	//Only gets 9 columns by default (8 actual data columns, ignoring the column defining the row numbers.)
	n->Scan();

}
