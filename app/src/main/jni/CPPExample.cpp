//
// Created by anisimov on 17.11.2017.
//

#include "net_sharp_dev_exampleskdapp_CppProvider.h"

JNIEXPORT jstring JNICALL Java_net_sharp_1dev_exampleskdapp_CppProvider_getCppString(JNIEnv *env, jobject){
 return (*env).NewStringUTF("IT WORKS!!!!!");
}