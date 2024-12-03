import paramiko
import time

# Verbindungsparameter
hostname = "192.168.3.15"  # IP-Adresse oder Hostname des Zielgeräts
port = 22  # Standard-SSH-Port
username = "root"
password = "root"

# Die Befehle
command_1 = "echo 'Erster Befehl ausgeführt'"
command_2 = "echo 'Zweiter Befehl ausgeführt'"

try:
    # SSH-Client erstellen
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())  # Unbekannte Hosts automatisch akzeptieren
    
    # Verbindung herstellen
    ssh.connect(hostname, port, username, password)
    print(f"Erfolgreich mit {hostname} verbunden.")
    
    # Ersten Befehl ausführen
    print(f"Führe Command_1 aus: {command_1}")
    stdin, stdout, stderr = ssh.exec_command(command_1)
    print(stdout.read().decode())  # Ausgabe des ersten Befehls
    print(stderr.read().decode())  # Fehler des ersten Befehls (falls vorhanden)
    
    # Verzögerung
    time.sleep(2)
    
    # Zweiten Befehl ausführen
    print(f"Führe Command_2 aus: {command_2}")
    stdin, stdout, stderr = ssh.exec_command(command_2)
    print(stdout.read().decode())  # Ausgabe des zweiten Befehls
    print(stderr.read().decode())  # Fehler des zweiten Befehls (falls vorhanden)

except Exception as e:
    print(f"Fehler: {e}")

finally:
    # Verbindung schließen
    ssh.close()
    print("Verbindung geschlossen.")
