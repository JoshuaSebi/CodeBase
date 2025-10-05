import matplotlib.pyplot as plt
import inspect
continents = ['Africa', 'Asia', 'Europe', 'North America', 'Oceania', 'South America',
'Soviet Union']
areas = [11.7, 10.4, 1.9, 9.4, 3.3, 6.9, 7.9]

plt.figure(figsize=(10,6))
plt.bar(continents, areas, color="skyblue")
plt.title("C vs A")
plt.xlabel("Continents")
plt.ylabel("Areas")

for i, area in enumerate(areas):
    plt.text(i, area+0.2, str(area))
plt.show()
