package net.sharp_dev.exampleskdapp;

/**
 * Created by anisimov on 17.11.2017.
 */

public class CppProvider {
    static {
        System.loadLibrary("CPPExample");
    }

    public  native String getCppString();
}
