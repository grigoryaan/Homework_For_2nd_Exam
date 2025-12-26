#include <iostream>

int main() {

	enum Or {
		erkushabti,
		ereqshabti,
		choreqshabti,
		hingshabti,
		urbat,
		shabat,
		kiraki
	};
	
	Or o = shabat;

	if (o == shabat or o == kiraki)
		std::cout << "hangstyan or ";
	else
		std::cout << "ashxataqayin or ";

	o = ereqshabti;

	if (o == shabat or o == kiraki)
		std::cout << "hangstyan or ";
	else
		std::cout << "ashxataqayin or ";

}
