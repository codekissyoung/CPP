#include <iostream>
void sayHello(void);
class Say
{
	private:
		char *string;

	public:
		Say( char *str )
		{
			string = str;
		}

		void sayThis()
		{
			std::cout << str << "from a static library \n";
		}

		void sayString(void);
}
