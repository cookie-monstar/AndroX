package com.cookie_monstar.www.xremote;

import android.os.Handler;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class MainActivity extends AppCompatActivity {
    private String url = "http://10.42.0.1:3000/mouse";
    private RequestQueue queue;
    private int previousX, previousY;
    private boolean isDouble;
    private long lastOneDown, justOneUp;
    private Handler handler;
    private Runnable keyUpEvent;
    private TextView textView;
    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textView);
        queue = Volley.newRequestQueue(this);
        isDouble = false;
        handler = new Handler();
        keyUpEvent = new Runnable() {
            @Override
            public void run() {
                textView.setText("down");
                sendMouseEvent("up=true");
            }
        };
    }
    private void sendMouseEvent(String request) {
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url+"?"+request, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                //do absolutely nothing
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("An error occured.");
            }
        });
        queue.add(stringRequest);
    }
    @Override public boolean onTouchEvent(MotionEvent event) {
        int x = (int)event.getX();
        int y = (int)event.getY();
        switch(event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                previousX = x;
                previousY = y;
                lastOneDown = SystemClock.uptimeMillis();
                if(lastOneDown-justOneUp<200) {
                    handler.removeCallbacks(keyUpEvent);
                    isDouble = true;
                }
                break;
            case MotionEvent.ACTION_UP:
                previousX = x;
                previousY = y;
                justOneUp = SystemClock.uptimeMillis();
                boolean isShort = justOneUp-lastOneDown<200;
                if(isDouble) {
                    isDouble = false;
                    if(isShort) {
                        sendMouseEvent("updownup=true");
                    } else {
                        sendMouseEvent("up=true");
                    }
                } else if(isShort) {
                    sendMouseEvent("down=true");
                    handler.postDelayed(keyUpEvent, 200);
                }
                break;
            case MotionEvent.ACTION_MOVE:
                if(previousX != x || previousY != y) {
                    sendMouseEvent("move=true&moveX="+Integer.toString(x-previousX)+"&moveY="+Integer.toString(y-previousY));
                    previousX = x;
                    previousY = y;
                }
                break;
        }
        return false;
    }
}