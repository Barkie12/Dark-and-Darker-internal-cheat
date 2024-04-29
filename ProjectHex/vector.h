class Vector3
{
public:
	double x, y, z;

	Vector3()
	{
		x = y = z = 0.0f;
	}

	Vector3(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	}

	Vector3(double XYZ)
	{
		x = XYZ; y = XYZ; z = XYZ;
	}

	Vector3(double* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector3(const double* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	inline Vector3& operator=(const Vector3& v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	inline Vector3& operator=(const double* v)
	{
		x = v[0]; y = v[1]; z = v[2]; return *this;
	}

	inline double& operator[](int i)
	{
		return ((double*)this)[i];
	}

	inline double operator[](int i) const
	{
		return ((double*)this)[i];
	}

	inline Vector3& operator+=(const Vector3& v)
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3& operator-=(const Vector3& v)
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	inline Vector3& operator*=(const Vector3& v)
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	inline Vector3& operator/=(const Vector3& v)
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	inline Vector3& operator+=(double v)
	{
		x += v; y += v; z += v; return *this;
	}

	inline Vector3& operator-=(double v)
	{
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3& operator*=(double v)
	{
		x *= v; y *= v; z *= v; return *this;
	}

	inline Vector3& operator/=(double v)
	{
		x /= v; y /= v; z /= v; return *this;
	}

	inline Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	inline Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator*(const Vector3& v) const
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	inline Vector3 operator/(const Vector3& v) const
	{
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	inline Vector3 operator+(double v) const
	{
		return Vector3(x + v, y + v, z + v);
	}

	inline Vector3 operator-(double v) const
	{
		return Vector3(x - v, y - v, z - v);
	}

	inline Vector3 operator*(double v) const
	{
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(double v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline double Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	inline double LengthSqr() const
	{
		return (x * x + y * y + z * z);
	}

	inline double LengthXY() const
	{
		return sqrtf(x * x + y * y);
	}

	inline double LengthXZ() const
	{
		return sqrtf(x * x + z * z);
	}

	inline double DistTo(const Vector3& v) const
	{
		return (*this - v).Length();
	}

	inline double Dot(const Vector3& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	inline Vector3 Cross(const Vector3& v) const
	{
		return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	inline bool IsZero() const
	{
		return (x > -0.01f && x < 0.01f
			&& y > -0.01f && y < 0.01f
			&& z > -0.01f && z < 0.01f);
	}

	inline void Reset()
	{
		x = 0.f; y = 0.f; z = 0.f;
	}
};
struct Vector2
{
public:
	float x;
	float y;
	inline Vector2() : x(0), y(0) {}
	inline Vector2(float x, float y) : x(x), y(y) {}
	inline float Distance(Vector2 v)
	{
		return sqrtf(((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y)));
	}
	inline Vector2 operator+(const Vector2& v) const
	{
		return Vector2(x + v.x, y + v.y);
	}
	inline Vector2 operator-(const Vector2& v) const
	{
		return Vector2(x - v.x, y - v.y);
	}
};