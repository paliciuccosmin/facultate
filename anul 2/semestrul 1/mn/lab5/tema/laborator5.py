############################################
##Student:Paliciuc Cosmin-Constantin       #
##Grupa:323AC                              #
############################################

import numpy as np
import matplotlib.pyplot as plt

# Se creeaza o matrice random de dimensiune 7*7
n = 7
A = np.random.rand(n, n)
# Se dau valorile pentru toleranta si numarul maxim de iteratii
tol = pow(10, -4)
maxiter = 5*100

# Se defineste functia pentru implementarea metodei puterii
def Metoda_puterii(matrix):
    # Se alege prima coloana din matricea data
    y = matrix[:, 0]
    # Se normalizeaza vectorul
    norm_y = np.linalg.norm(y)
    y = y / norm_y
    # Se initializeaza numarul de iteratii si eroarea
    i = 0
    error = np.zeros((len(matrix), 1))
    error[i] = 1     

    while error[i] > tol:
        if i >= maxiter:
            print("S-a atins numarul maxim de iteratii fara a se fi obtinut nivelul tolerantei.")
            break
        # Se obtine vectorul propriu pentru valoarea dominanta
        z = matrix @ y
        norm_z = np.linalg.norm(z)
        z = z / norm_z
        # Se actualizeaza eroarea
        error[i+1] = abs(1 - abs(np.dot(np.transpose(z), y)))
        y = z
        i += 1
    # Se calculeaza valoarea proprie dominanta
    dominant_value = np.dot(y, matrix @ y)
    return y, dominant_value, error, i

# Se defineste functia pentru implementarea metodei puterii inverse
def Metoda_puterii_inverse(matrix):
    # Se alege prima coloana din matricea data
    y = matrix[:, 0]
    # Se normalizeaza vectorul
    norm_y = np.linalg.norm(y)
    y = y / norm_y
    # Se initializeaza numarul de iteratii si eroarea
    i = 0
    error = np.zeros((len(matrix), 1))
    error[i] = 1

    while error[i] > tol:
        if i >= maxiter:
            print("S-a atins numarul maxim de iteratii fara a se fi obtinut nivelul tolerantei.")
            break
        # Se alege un scalar numit deplasare
        miu = np.transpose(y).dot(A).dot(y)
        # Se rezolva sistemul pentru a obtine vectorul
        z = np.linalg.solve(miu * np.identity(len(matrix)) - matrix, y)
        norm_z = np.linalg.norm(z)
        z = z / norm_z
        # Se actualizeaza eroarea
        error[i+1] = abs(1 - abs(np.dot(np.transpose(z), y)))
        y = z
        i += 1
    # Se calculeaza ultima valoare din catul Rayleigh care este si valoarea proprie dominanta
    dominant_value = miu

    return y, dominant_value, error, i

# Se afiseaza datele pentru metoda puterii
dominant_power, dominant_value_power, error_power, num_is_power = Metoda_puterii(A)

print("Vectorul propriu dominant pentru Metoda Puterii este: ",dominant_power)
print("Valoarea proprie dominanta pentru Metoda Puterii este: ",dominant_value_power)
print("Eroarea folosind Metoda Puterii este: ",error_power,"\n")

# Se calculeaza datele pentru metoda puterii inverse
dominant_inverse_power, dominant_value_inverse_power, error_inverse_power, num_is_inverse_power = Metoda_puterii_inverse(A)

print("Vectorul propriu dominant pentru Metoda Puterii Inverse este: ",dominant_inverse_power)
print("Valoarea proprie dominanta pentru Metoda Puterii Inverse este: ",dominant_value_inverse_power)
print("Eroare folosind Metoda puterii inverse este: ",error_inverse_power,"\n")

# Verificare
print("Verificare folosind comanda predefinita", np.linalg.eig(A))

# Se creeaza un vector pâna la numarul de iteratii
i_power = np.arange(1, num_is_power + 1)
i_inverse_power = np.arange(1, num_is_inverse_power + 1)
# Se reprezinta grafic dependenta dintre eroare si numarul de iteratii a celor doua metode
plt.semilogy(i_power, error_power[:num_is_power], color='purple') 
plt.semilogy(i_inverse_power, error_inverse_power[:num_is_inverse_power], color='black')  

# Se realizeaza titlul, legenda si numele axelor
plt.title('Comparatie intre metodele puterii si puterii inverse')
plt.legend(['Metoda Puterii ','Metoda Puterii Inverse'])
plt.xlabel('Numar Iteratii')
plt.ylabel('Eroare')
plt.show()