#include <stdio.h>
int counter = 0;
__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){
	counter ++;
	printf("Function entered %p from %p\n", this_fn,call_site);
}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){

	printf("Function exited %p from %p\n", this_fn, call_site);

}

