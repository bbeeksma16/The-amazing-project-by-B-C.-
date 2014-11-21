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
	b.setWeight(1764);
	c.setName("Subaru Forester");
	c.setWeight(3153);
	d.setName("Toyota Prius");
	d.setWeight(3042);
	e.setName("Ferrari Italia");
	e.setWeight(3274);
	f.setName("Bugatti Veyron");
	f.setWeight(4044);
	g.setName("Tesla Model S");
	g.setWeight(4647);
	h.setName("Leopard 2 Tank");
	h.setWeight(90000);
	i.setName("KNTV Smart Car");
	i.setWeight(1800);
	j.setName("Toyota Camry");
	j.setWeight(3190);

	Cars[0] = a;
	Cars[1] = b;
	Cars[2] = c;
	Cars[3] = d;
	Cars[4] = e;
	Cars[5] = f;
	Cars[6] = g;
	Cars[7] = h;
	Cars[8] = i;
	Cars[9] = j;

	return Cars;
}