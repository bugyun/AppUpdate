package vip.ruoyun.update;

public class AppUpdate {

    static {
        System.loadLibrary("appUpdate");
    }

    public static native void bspatch(String oldApk, String patchPath, String newApk);


    public void test() {
        bspatch("", "", "");
    }
}
