import numpy as np
import matplotlib.pyplot as plt

rng = np.random.default_rng(0)
n = 7
A = rng.integers(1, 75, size=(n, n))
tol = pow(10, -4)
maxiter = 5*100

# Metoda puterii
def met_puterii(A,n):
    y = [row[1] for row in A]
    y = np.divide(y, np.linalg.norm(y, 1))
    i = 0
    e = np.zeros((n, 1))
    e[i] = 1
    while (e[i] > tol):
        if (i > maxiter):
            print('S-a atins numarul maxim de iteratii fara a se fi obtinut nivelul prescris al tolerantei.\n')
            break
        z = np.dot(A, y)
        z = np.divide(z, np.linalg.norm(z))
        e[i+1] = abs(1-abs(np.transpose(z).dot(y)))
        y = z
        i = i+1
    val_proprie = np.divide(np.dot(A, y), y)[0]
    return z, val_proprie, e, i
# Metoda puterii inverse
def met_puterii_inv(A, n):

    y = [row[1] for row in A]
    y = np.divide(y, np.linalg.norm(y))
    i = 0
    e = np.zeros((n, 1))
    e[i] = 1
    while (e[i] > tol):
        if (i > maxiter):
            print('S-a atins numarul maxim de iteratii fara a se fi obtinut nivelul prescris al tolerantei.\n')
            break
        miu = np.transpose(y).dot(A).dot(y)
        z = np.linalg.solve(miu*np.identity(n)-A, y)
        z = np.divide(z, np.linalg.norm(z))
        e[i+1] = abs(1-abs(np.transpose(z).dot(y)))
        y = z
        i = i + 1
    val_proprie = np.transpose(np.power(y, i-2)).dot(A).dot(np.power(y, i-2))
    return z, val_proprie, e, i
z1, val_proprie1, e_dominanta1, nr_i_1 = met_puterii(A, n)
z2, val_proprie2, e_dominanta2, nr_i2 = met_puterii_inv(A, n)
#  afisarea rezultatelor
print("vectori de valori proprii si valoare dominanta ", z2,val_proprie2)
# verificare
print("Verificare folosind comanda predefinita", np.linalg.eig(A))
# afisare grafic
i = np.linspace(0, 6, num = 7)
plt.plot(i, e_dominanta1,'blue')
plt.plot(i, e_dominanta2,'red')
plt.title('Comparatie intre metodele puterii si puterii inverse pentru n = %i' % n)
plt.legend(['Metoda Puterii ', 'Metoda Puterii Inverse'])
plt.xlabel('nr iteratii')
plt.ylabel('Erori')
plt.show()