/*
 ============================================================================
 Autor   : Michel Nascimento
 E-mail   : mhsn@a.recife.ifpe.edu.br
 Data     : 20/07/2017
 Titulo   : Código mq9 calibração
 ============================================================================
 */

// Calibração de sensores mq9 para detecção de CO
// níveis CO https://www.abe.iastate.edu/extension-and-outreach/carbon-monoxide-concentrations-table-aen-172/

void setup() {
    Serial.begin(9600);
}

void loop() {
    
    // Voltagem no sensor
    float sensor_volt;

    // Resistência superficial do sensor
    float rS;

    // Razão entre RS e R0
    float razao; 

    // Leitura da porta analógica A0
    int sensorValue = analogRead(A0);

    int mqR = 10000;

    // Para Vcc 3.3v
    sensor_volt=(float)sensorValue/1024*3.3;

    // Cálculo do RS
     rS = ((1024.0 * mqR) / sensorValue) - mqR;

    /*
     * R0 - Parâmetro definido no esquema de calibração do sensor, 
     * Uso de método de calibração adequado
     * às condições
     */
     
    float r0 = 1211.39;

    razao = rS/r0;

    // Valores do sensor Calibrado
    Serial.print("Voltagem no Sensor = ");
    Serial.println(sensor_volt);
    Serial.print("Resistência da Superficie = ");
    Serial.println(rS);
    Serial.print("Rs/R0 = ");
    Serial.println(razao);   


    // Função transformada  baseada na calibração
    float f = exp(log((rS/r0)/20.48)/-0.4687);

    Serial.println("\n\n");
    Serial.print("CO:"); 
    Serial.print(f); 
    Serial.println("ppm");
    delay(2000);

    

}
