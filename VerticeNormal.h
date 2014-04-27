//---------------------------------------------------------------------------

#ifndef VerticeNormalH
#define VerticeNormalH
//---------------------------------------------------------------------------
class VerticeNormal{

        private:
                int indiceVertice;
                int indiceNormal;

        public:
                VerticeNormal(int iV, int iN);
                int getIndiceNormal(){return indiceNormal;};
                int getIndiceVertice(){return indiceVertice;};

};

#endif
