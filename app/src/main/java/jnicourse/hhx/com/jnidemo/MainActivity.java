package jnicourse.hhx.com.jnidemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("NdkTest");
    }

    StaticTest staticTest = new StaticTest();
    DynamicTest dynamicTest = new DynamicTest();
    DynamicTest2 dynamicTest2 = new DynamicTest2();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void staticBind(View v) {
        Toast.makeText(this, staticTest.doAdd(1, 2) + "", Toast.LENGTH_SHORT).show();
    }

    public void dynamicBind(View v) {
        Toast.makeText(this, dynamicTest.doTwo(1, 2) + "", Toast.LENGTH_SHORT).show();
    }

    public void dynamicBind2(View v) {
        Toast.makeText(this, dynamicTest2.doTwo(3, 5) + "", Toast.LENGTH_SHORT).show();
    }
}
