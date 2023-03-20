#include <iostream>
#include <vector>
#include <algorithm>

struct punct 
{
    int x, y;
};

bool esteDreptunghi(punct p1, punct p2, punct p3, punct p4) 
{
    vector<punct> coordonate_dreptunghi = { p1, p2, p3, p4 };
    std::sort(coordonate_dreptunghi.begin(), coordonate_dreptunghi.end(), [](punct a, punct b)
        {
            if (a.x == b.x) 
            {
                return a.y < b.y;
            }
        return a.x < b.x;
        });

    // Verificam daca punctele formeaza un dreptunghi
    return points[0].x == points[1].x && points[2].x == points[3].x &&
        points[0].y == points[2].y && points[1].y == points[3].y &&
        points[1].x - points[0].x == points[3].x - points[2].x &&
        points[2].y - points[0].y == points[3].y - points[1].y;
}

int main() {
    // Citim numarul de puncte
    int n;
    cout << "Introduceti numarul de puncte: ";
    cin >> n;

    // Citim punctele
    vector<Point> points(n);
    cout << "Introduceti coordonatele punctelor (x, y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Cautam perechile de puncte care formeaza un dreptunghi
    bool found = false;
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (isRectangle(points[i], points[j], points[k], points[l])) 
                    {
                        cout << "(" << points[i].x << ", " << points[i].y << "), ";
                        cout << "(" << points[j].x << ", " << points[j].y << "), ";
                        cout << "(" << points[k].x << ", " << points[k].y << "), ";
                        cout << "(" << points[l].x << ", " << points[l].y << ")" << std::endl;
                        found = true;
                    }
                }
            }
        }
    }

    if (!found)
        std::cout << "Nu s-au gasit perechi care sa formeze un dreptunghi.";
        return 0;
}
