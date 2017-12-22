//
//The vertically stacked rectangular paper ribbon with the fixed lower end of the steel was folded as follows :
//-at the first step it was bent in half so that the upper half fell on the lower
//either from the front(F - flexion) or from the rear(B bending),
//-in the next n - 1 steps, a similar action was performed with the resulting
//the previous step bent ribbon, as with a single whole.
//Then the ribbon was unfolded, bringing it to its original state.On it remained
//folds - ribs from kinks, with some of the ribs being directed
//convexity to us(K - ribs), and some - from us(O - edges).Ribs
//numbered from top to bottom by numbers from 1 to 2n - 1.
//A.Create a program that requests a string of characters from uppercase letters
//"P" and "3", which determines the sequence of types of flexions, is the number of the edge, and
//the type of this edge obtained after the given
//of the flexion sequence.
//B.Create a program that requests a string of characters from uppercase letters
//"O" and "K", where the location on the i - th place of the symbol "O" or "K" determines the type
//ribs on a straightened strip, and issuing a string of uppercase "F" and "B",
//Determining the sequence of types of flexions by means of which
//A ribbon with an original sequence of edges is obtained.If there is no such line
//exists, report it.

#include <iostream>
#include <string>
using namespace std;


char vergetypeCalc(string seq, int N)
{
	int p = pow(2, seq.size());
	if (N >= p)
		return 0;
	int n = N;
	while (n % 2 == 0)
	{
		n /= 2;
		p /= 2;
	}
	int index1 = log(p) / log(2) - 1;
	int index2 = p/2 - (n - 1) / 2;
	if ( ( seq[index1] == 'F' && index2 % 2 == 0 ) || ( seq[index1] == 'B' && index2 % 2 == 1 ) )
		return 'K';
	else return 'O';
}


string bendseqCalc(string seq)
{
	string result = "";
	int i = 1;
	while (i <= (seq.size() + 1)/ 2)
	{
		int tmp = log(i) / log(2);
		if (seq[seq.size() - i] == 'K')
			result += "B";
		else result += "F";
		i *= 2;
	}
	return result;
}


int main()
{
	string seq;
	cout << "Enter sequence of bendings (F - front, B - back) : ";
	cin >> seq;

	int n;
	cout << "Enter verge number: ";
	cin >> n;

	cout << vergetypeCalc(seq, n) << endl;

	cout << "Enter sequence of verges (K - convex, O - concave) : ";
	cin >> seq;
	cout << bendseqCalc(seq) << endl;



	system("pause");
	return 0;
}