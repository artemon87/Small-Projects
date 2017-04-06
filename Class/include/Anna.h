#ifndef ANNA_H
#define ANNA_H


class Anna
{
    public:
        Anna();
        Anna(int h, int m, int s);
        //void setAge(int y, int m, int d);
        void duration(int h, double m, double s);
        const int getHours()const;
        const int getMinutes()const;
        const int getSoconds()const;
        void setHours(int);
        void setMinutes(int);
        void setSoconds(int);

        virtual ~Anna();
    private:
        int year;
        int month;
        int day;
        int hours, minutes, seconds;

};

#endif // ANNA_H
