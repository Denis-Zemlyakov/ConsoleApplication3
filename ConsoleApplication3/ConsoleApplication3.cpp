#include <iostream>
#include <string>

using namespace std;

enum _errors
{
    OK,
    WRONG
};

enum _collors_name
{
    RESET,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGNETA,
    CYAN
};

class Collor {

    private:

        static _collors_name collorName;
        static string collorCode;

        static string _reset;
        static string _red;
        static string _green;
        static string _yellow;
        static string _blue;
        static string _magneta;
        static string _cyan;

        Collor() = delete;
        
    public:
        
        static _errors setCollor(_collors_name col) {
            switch (col)
            {
                case RESET:
                    collorName = RESET;
                    collorCode = _reset;
                    break;
                case RED:
                    collorName = RED;
                    collorCode = _red;
                    break;
                case GREEN:
                    collorName = GREEN;
                    collorCode = _green;
                    break;
                case YELLOW:
                    collorName = YELLOW;
                    collorCode = _yellow;
                    break;
                case BLUE:
                    collorName = BLUE;
                    collorCode = _blue;
                    break;
                case MAGNETA:
                    collorName = MAGNETA;
                    collorCode = _magneta;
                    break;
                case CYAN:
                    collorName = CYAN;
                    collorCode = _cyan;
                    break;
                default:
                    return _errors::WRONG;
                    break;
            }
            return _errors::OK;
        }

        static _collors_name getCollor() {
            return collorName;
        }
            
        static string getCodeCollor() {
            return collorCode;
        }

        static string reset() {
            return _reset;
        }

        

        static int print(string value) {
            cout << getCodeCollor() << value << reset() << endl;
            return 0;
        }

        template <typename T>
        static int print(T value) {
			cout << getCodeCollor() << value << reset() <<  endl;
            return 0;
        }

        template <typename T>
        static int print(T* value, size_t size) {
            cout << getCodeCollor();
            for (size_t i = 0; i < size; i++)
            {
                cout << value[i] << endl;
            }
            cout << reset();
            return 0;
        }

        template <typename T>
        static int print(T* value, size_t size, size_t subSize) {
            cout << getCodeCollor();
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = 0; j < subSize; j++)
                {
                    cout << value[i][j] << " ";
                }
				cout << endl;
            }
            cout << reset();
            return 0;
        }
};

_collors_name Collor::collorName = RESET;
string Collor::collorCode = "\033[0m";
string Collor::_reset = "\033[0m";
string Collor::_red = "\033[31m";
string Collor::_green = "\033[32m";
string Collor::_yellow = "\033[33m";
string Collor::_blue = "\033[34m";
string Collor::_magneta = "\033[35m";
string Collor::_cyan = "\033[36m";


int main()
{
	int a[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    Collor::setCollor(RED);
    Collor::print("Hello, world!");
	Collor::setCollor(GREEN);
	Collor::print(a, 3, 2);
}
