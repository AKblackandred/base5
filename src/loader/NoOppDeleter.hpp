struct NoOppDeleter
{
    template <typename T>
    void operator()(T* p) const noexcept
    {
        // no-op
    }
};