package com.rollofdice.oem.rollofdice;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import pl.model.polsl.Model;

public class MainActivity extends AppCompatActivity {
    Model model = new Model();//model field with logic and computations

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final Integer[] result = new Integer[1];

        //set all buttons etc
        Button btnMax = findViewById(R.id.btnMax);
        Button btnSum = findViewById(R.id.btnSum);
        final TextView showResult = findViewById(R.id.textResult);
        final TextView viewDices = findViewById(R.id.textDices);
        final TextView viewWalls = findViewById(R.id.textWalls);
        SeekBar seekDices = findViewById(R.id.seekDices);
        SeekBar seekWalls = findViewById(R.id.seekWalls);
        model.setNumOfWalls(4);
        model.setNumOfDices(1);

        //set what happens
        seekDices.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                Integer valueD;
                if(i<1)
                    valueD = i + 1;
                else
                    valueD = i;
                viewDices.setText("" + valueD);
                model.setNumOfDices(valueD);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        seekWalls.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                Integer valueW;
                if(i<4)
                    valueW = i + 4;
                else
                    valueW = i;
                viewWalls.setText("" + valueW);
                model.setNumOfWalls(valueW);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        btnMax.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                model.setMode("max");
                model.throwDices();
                result[0] = model.getResult();
                showResult.setText("Max rolled number is: " + result[0]);
            }
        });

        btnSum.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                model.setMode("sum");
                model.throwDices();
                result[0] = model.getResult();
                showResult.setText("Sum of thrown dices is: " + result[0]);

            }
        });

    }
}
