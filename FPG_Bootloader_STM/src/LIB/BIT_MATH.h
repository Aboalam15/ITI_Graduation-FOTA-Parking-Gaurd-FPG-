#define     SET_BIT(var,BitNO)              (var=(var|(1<<BitNO)))

#define     CLR_BIT(var,BitNO)              (var=(var&~(1<<BitNO)))
	
#define     TOGGLE_BIT(var,BitNO)           (var=(var^(1<<BitNO)))

#define     GET_BIT(var,BitNO)              ((var>>BitNO)&1)
