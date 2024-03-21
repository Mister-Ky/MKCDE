#pragma once

#ifndef MK_APP_HPP
#define MK_APP_HPP

namespace mk
{
class App
{
public:
	App();
	virtual ~App();

	virtual void init() = 0;
	virtual void run() = 0;
	virtual void shutdown() = 0;
};
}

#endif
