/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 18:12:14 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/18 18:52:56 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MONITOR_DISPLAY
# define I_MONITOR_DISPLAY

#include "IMonitorModule.class.hpp"

class			IMonitorDisplay {
	public :
		virtual int			init(void) const = 0;
		virtual void		drawModule(IMonitorModule & module) const = 0;
		virtual void		interpretData(std::string const & data) const = 0;
		virtual int			end(void) const = 0;
};

#endif
