typedef ll Tcoord;
struct Tpoint
{
      ll x,y;

      friend istream & operator >> (istream &in , Tpoint &A)
      {
            in >> A.x >> A.y;
            return in;
      }
};
typedef Tpoint Tvector;
Tvector operator +(const Tvector& u, const Tvector& v)
{
    return {u.x + v.x, u.y + v.y};
}
Tcoord operator % (Tvector &A , Tvector &B)
{
      return A.x*B.x + A.y*B.y;
}

Tcoord operator *(Tvector &A , Tvector &B)
{
      return A.x*B.y -  B.x*A.y;
}

Tvector operator -(const Tvector& u, const Tvector& v)
{
    return {u.x - v.x, u.y - v.y};
}
int pos(Tpoint A)
{
      if(A.y < 0) return -1;
      if(A.y == 0 && A.x > 0) return 0;
      return 1;
}
bool cmp(Tpoint A , Tpoint B)
{
      int posa = pos(A) , posb = pos(B);
      if(posa != posb) return posa < posb;
      return A.x*B.y > A.y*B.x;
}
int CCW(Tpoint &A , Tpoint &B , Tpoint &C)
{
      Tvector AB  = {B.x - A.x , B.y-A.y} , BC = {C.x - B.x , C.y-B.y};
      if( AB*BC >  0 ) return 1;
      if(AB*BC < 0) return -1;
      return 0;
}
