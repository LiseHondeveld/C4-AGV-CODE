
//maak oproepbare int aan

//als linker ultrasone sensor iets ziet gaat de rechte wiel naar voren draaien en
//dan naar links rijden tot dat de ultrasone sensor niets meer ziet

if agv_ultrasoon_voor_links >5 & <20
{

}

//als rechter ultrasone sensor iets ziet
// dan naar rechts rijden tot dat de ultrasone sensor niets meer ziet

else if agv_ultrasoon_voor_rechts >5 & <20
{

}

// als voor ultrasone sensor iets ziet in the range tussen 5 en 20 centimeter. de twee wielen gaan dan allebei naar voren.
//De motoren stoppen als de afstand minder is dan 5 centimeter.
//dan naar voren rijden tot dat de ultrasone sensot niets meer ziet
else if agv_ultrasoon_voor_midden >5 & <20
{

}
else
