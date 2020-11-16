#pragma once
template <class T>
class AbstractResponseHandler
{
	virtual void handle(const T& response) const = 0;
public:
	void operator()(const T& response) const;
	virtual ~AbstractResponseHandler() = default;
};

template<class T>
class FunctionResponseHandler : public AbstractResponseHandler<T>
{
	std::function<void(const T&)> handler_;

	void handle(const T& response) const override;
public:
	explicit FunctionResponseHandler(const std::function<void(const T&)>&);

};

template <class T>
void AbstractResponseHandler<T>::operator()(const T& response) const
{
	handle(response);
}

template <class T>
void FunctionResponseHandler<T>::handle(const T& response) const
{
	handler_(response);
}

template <class T>
FunctionResponseHandler<T>::FunctionResponseHandler(const std::function<void(const T&)>& func)
{
	handler_ = func;
}