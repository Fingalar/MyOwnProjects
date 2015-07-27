// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/18 18:12:19 by po-conno          #+#    #+#             //
//   Updated: 2015/04/18 18:47:18 by po-conno         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

class		IMonitorModule {
public:
//	virtual	IMonitorModule(void) = 0;
//	virtual ~IMonitorModule(void) = 0;

	virtual std::vector<std::string>	getDatas(void) = 0;

//private:
//	virtual IMonitorModule(IMonitorModule const & src) = 0;

};

#endif
