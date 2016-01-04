#include <stdio.h>

class A {
	public:
		A(int fd);
		A(void *h);
		union {
			void *handle;
			int	fd;
		} m_handle;
};

A::A(int fd)
{
	m_handle.fd = fd;
}

A::A(void *h)
{
	m_handle.handle = h;
}

int
main(void)
{
	return 0;
}
