#ifndef C2DE45C0_E0D0_4635_BDB9_CB9880798B7B
#define C2DE45C0_E0D0_4635_BDB9_CB9880798B7B

class Ps
{
private:
    int _price;
    int _quality;
    int _generation;

public:
    Ps(int price, int quality, int generation)
        : _price(price), _quality(quality), _generation(generation)
    {
    }

    int getPrice() const
    {
        return _price;
    }

    int getQuality() const
    {
        return _quality;
    }
     int getGeneration() const
    {
        return _generation;
    }
};

#endif /* C2DE45C0_E0D0_4635_BDB9_CB9880798B7B */
