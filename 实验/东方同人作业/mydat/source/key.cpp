#include "../include/GV.h"

unsigned int stateKey[256];

int GetHitKeyStateAll_2(){
    char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll( GetHitKeyStateAll_Key );
    for(int i=0;i<256;i++){
        if(GetHitKeyStateAll_Key[i]==1) stateKey[i]++;
        else                            stateKey[i]=0;
    }
    return 0;
}

int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

pad_t pad;
void input_pad_or_key(int *p,int k){
	*p=*p>k?*p:k;
}

void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput=GetJoypadInputState(DX_INPUT_PAD1);
	for(i=0;i<16;i++){
		if(PadInput&mul) pad.key[i]++;
		else             pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]   ,CheckStateKey(KEY_INPUT_LEFT    ));
	input_pad_or_key(&pad.key[configpad.up]     ,CheckStateKey(KEY_INPUT_UP      ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT   ));
	input_pad_or_key(&pad.key[configpad.down]   ,CheckStateKey(KEY_INPUT_DOWN    ));
	input_pad_or_key(&pad.key[configpad.shot]   ,CheckStateKey(KEY_INPUT_Z       ));
	input_pad_or_key(&pad.key[configpad.bom]    ,CheckStateKey(KEY_INPUT_X       ));
	input_pad_or_key(&pad.key[configpad.slow]   ,CheckStateKey(KEY_INPUT_LSHIFT  ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE  ));
	input_pad_or_key(&pad.key[configpad.change] ,CheckStateKey(KEY_INPUT_LCONTROL));
}
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("向CheckStatePad中传入了错误的键值\n");
		return -1;
	}
}
