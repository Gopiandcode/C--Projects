#ifndef USER_H
#define USER_H
class User {

	public:
		User();
		char GetCommand();
	private:
		virtual void ShowMenu();
		virtual int IsLegal(char cmd);

};
#endif //USER_H
