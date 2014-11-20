#include <vector>
#include "Car.h"
using namespace std;

vector<Car> CarsIntoVector()
{
	vector<Car> Cars(10);

	Car a, b, c, d, e, f, g, h, i, j;

	a.setName("Nissan Pickup Truck");
	a.setWeight(5038);
	b.setName("Volkswagon Beetle");
	b.setWeight(5038);
	c.setName("Subaru Forester");
	c.setWeight(5038);
	d.setName("Toyota Prius");
	d.setWeight(5038);
	e.setName("Ferrari Italia");
	e.setWeight(5038);
	f.setName("Bugatti Veyron");
	f.setWeight(4044);
	g.setName("Tesla Model S");
	g.setWeight(5038);
	h.setName("Leopard 2 Tank");
	h.setWeight(90000);
	i.setName("KNTV Smart Car");
	i.setWeight(1800);
	j.setName("Toyota Camry");
	j.setWeight(3190);

	for (int i = 0; i < 10; i++)
	{
		char car = 'a';
		Cars[i] = car;
		a++;

	return Cars;
}