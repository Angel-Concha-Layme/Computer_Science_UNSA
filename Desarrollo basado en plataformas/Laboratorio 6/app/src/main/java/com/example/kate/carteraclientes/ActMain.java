package com.example.kate.carteraclientes;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;

import com.example.kate.carteraclientes.BaseDatos.DatosOpenHelper;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.RecyclerView;

import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

public class ActMain extends AppCompatActivity {
    private ListView lstDatos;
    private ArrayAdapter<String> adaptador;
    private ArrayList<String> clientes;

    private SQLiteDatabase conexion;
    private DatosOpenHelper datosOpenHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton)findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent it = new Intent( ActMain.this, ActNuevoCliente.class);
                //startActivity(it);
                startActivityForResult(it, 0);
            }
        });

        actualizar();
    }

    private void actualizar(){
        lstDatos = findViewById(R.id.lstDatos);
        clientes=new ArrayList<String>();

        try {
            datosOpenHelper = new DatosOpenHelper(this);
            conexion = datosOpenHelper.getWritableDatabase();
            StringBuilder sql = new StringBuilder();
            sql.append("SELECT * FROM CLIENTE");
            String sNombre;
            String sTelefono;

            Cursor resultado = conexion.rawQuery(sql.toString(), null);

            if (resultado.getCount() > 0){
                resultado.moveToFirst();
                do {
                    sNombre = resultado.getString(resultado.getColumnIndex("NOMBRE"));
                    sTelefono = resultado.getString(resultado.getColumnIndex("TELEFONO"));
                    clientes.add(sNombre + ": " + sTelefono);
                }
                while (resultado.moveToNext());
            }

            adaptador = new ArrayAdapter<String>(this, android.R.layout.simple_expandable_list_item_1, clientes);
            lstDatos.setAdapter(adaptador);

        }
        catch (Exception ex){
            AlertDialog.Builder dlg = new AlertDialog.Builder(this);
            dlg.setTitle("Aviso");
            dlg.setMessage(ex.getMessage());
            dlg.setNeutralButton("Ok", null);
            dlg.show();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        actualizar();
    }

}
