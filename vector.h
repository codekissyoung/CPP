class Vector {

    private:
        double* elem;
        int sz;

    public:
        // 构建一个Vector
        Vector( int s );
        
        // 通过下标访问元素
        double& operator[]( int i );

        int size();
        
        void read();

        double sum();
};
