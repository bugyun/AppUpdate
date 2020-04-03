//
// Created by ruoyun on 2020/4/3.
//

#include <jni.h>
#include <string>


extern "C" {
extern int bspatch_main(int argc, char *argv[]);
}


extern "C" JNIEXPORT void JNICALL
Java_vip_ruoyun_update_AppUpdate_bspatch(
    JNIEnv *env, jclass clazz,
    jstring j_old_apk,
    jstring j_patch_path,
    jstring j_new_apk) {
  const char *oldApk = env->GetStringUTFChars(j_old_apk, nullptr);
  const char *patchPath = env->GetStringUTFChars(j_patch_path, nullptr);
  const char *newApk = env->GetStringUTFChars(j_new_apk, nullptr);
  char *argv[4] = {const_cast<char *>(""), const_cast<char *>(oldApk), const_cast<char *>(newApk),
                   const_cast<char *>(patchPath)};
  bspatch_main(4, argv);
  env->ReleaseStringUTFChars(j_old_apk, oldApk);
  env->ReleaseStringUTFChars(j_patch_path, patchPath);
  env->ReleaseStringUTFChars(j_new_apk, newApk);
}
