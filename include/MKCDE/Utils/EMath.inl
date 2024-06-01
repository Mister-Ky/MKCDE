
template <typename T>
constexpr inline const T sign(const T sn)
{
	return sn > 0 ? +1.0f : (sn < 0 ? -1.0f : 0.0f);
}
