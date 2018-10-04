/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackPubSub_PubSubState_h__
#define __OpcUaStackPubSub_PubSubState_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to expose and control the operation of a PubSub component.
	 */
	class DLLEXPORT PubSubState
	{
	  public:
		typedef boost::shared_ptr<PubSubState> SPtr;

		typedef enum
		{
			Disabled,		//!< The PubSub component is configured but currently disabled.
			Paused,			//!< The PubSub component is enabled but currently paused by a parent component. The
							//!< parent component is either Disabled or Paused.
			Operational,	//!< The PubSub component is operational.
			Error			//!< The PubSub component is in an error state.
		} State;

		/**
		 * constructor
		 */
		PubSubState(void);

		/**
		 * destructor
		 */
		virtual ~PubSubState(void);

		/**
		 * This method returns the state
		 *
		 * @return state
		 */
		State state(void);

		/**
		 * This method is used to set the pointer to the parent class
		 *
		 * @param[in] parent	 	pointer to parent class
		 */
		void parent(
			const PubSubState::SPtr& parent
		);

		/**
		 * This method indicates that the component will be enable
		 *
		 * @return status of component
		 */
		State enable(void);

		/**
		 * This method indicates that the component will be disable
		 *
		 * @return status of component
		 */
		State disable(void);

		/**
		 * This method indicates that the component will be in error state
		 *
		 * @return status of component
		 */
		State errorOn(void);

		/**
		 * This method indicates that the component will be leave the error state
		 *
		 * @return status of component
		 */
		State errorOff(void);

		/**
		 * This method indicates that the parent component will be changed to
		 * disable or paused state
		 *
		 * @return status of component
		 */
		State parentChangedToDisableOrPaused(void);

		/**
		 * This method indicates that the parent component will be changed to
		 * operational or paused state
		 *
		 * @return status of component
		 */
		State parentChangedToOperational(void);

		/**
		 * This method is a virtual method and is called if the state of the
		 * component has changed
		 *
		 *  @param[in] state new state of the component
		 */
		virtual void handleStateChange(State state);


	  private:
		State parentState(void);

		State state_;				//!< state of the publish subscribe component
		PubSubState::SPtr parent_;	//!< pointer to parent class

	};

}

#endif
