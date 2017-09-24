// we use the header to convey the general design of the object,
// without spending too much time considering the implementation
class Display {
	public:
		Display(int lim); 		// a display should support 
		void Increment();               //     being incremented
		void SetValue(int value);       //     setting values
		int GetValue();                 //     getting values
		void Show();                    //     being displayed
		int GetLimit();                 //     getting the maximum
	private:                                // and contains
		int limit,                      // an internal limit
		    value;                      // and a value
};

class Timer {
	public:
		Timer();                        // A timer should support
		void Increment();               //       being incremented
		void Set();                     //       being set to a value
		void Show();                    //       being shown

	private:                                // and contains
		Display hours,                  // an hours display
			minutes;                // a minutes display 
};

