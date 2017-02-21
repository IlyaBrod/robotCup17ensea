from math import *

"""Module de calcul des constantes de triangulisation"""

print("Module de calcul des constantes de triangulisation\n")
print(""" Organisation du terrain :
				3 				3
	1					ou 					1
				2				2
""")


print("Saisir les coordonnees des balises : \n")
X1 = float(raw_input("X1 : "))
Y1 = float(raw_input("Y1 : "))
print("")
X2 = float(raw_input("X2 : "))
Y2 = float(raw_input("Y2 : "))
print("")
X3 = float(raw_input("X3 : "))
Y3 = float(raw_input("Y3 : "))

P1_NORM2 = X1*X1 + Y1*Y1
P2_NORM2 = X2*X2 + Y2*Y2
P3_NORM2 = X3*X3 + Y3*Y3
D12X = X2-X1
D12Y = Y2-Y1
D13X = X3-X1
D13Y = Y3-Y1


DMID_BOT = X2-X1
DMID_TOP = sqrt((DMID_BOT/2)**2+(Y1-Y2)**2)
DTOP_BOT =sqrt((DMID_BOT/2)**2+(Y1-Y2)**2)
MAP_ANGLE = 180 - (180 - (acos(DTOP_BOT/(2*DMID_TOP))) - 90)


if(D12X==0):
	print("D12X null, erreur dans le positionnement des balises")
else:
	print("\n//GENERATED CODE :")
	print("#define P1_NORM2 "+str(P1_NORM2))
	print("#define P2_NORM2 "+str(P2_NORM2))
	print("#define P3_NORM2 "+str(P3_NORM2))
	print("#define D12X "+str(D12X))
	print("#define D12Y "+str(D12Y))
	print("#define D13X "+str(D13X))
	print("#define D13Y "+str(D13Y))

	print("//END GENERATED CODE")

raw_input("Appuyez sur une touche pour quitter")
