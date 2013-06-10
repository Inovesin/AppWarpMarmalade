
namespace AppWarp
{
	typedef unsigned char byte;
	const int MAX_PROPERTY_SIZE_BYTES = 2048;

	struct response_struct
	{
		int messageType;
		int requestType;
		int resultCode;
		int reserved;
		int payLoadType;
		int payLoadSize;
		byte *payLoad;
	};
	typedef response_struct response; 

	struct notify_struct
	{
		int messageType;
		int updateType;
		int reserved;
		int payLoadType;
		int payLoadSize;
		byte *payLoad;
	};
	typedef notify_struct notify; 

	const int result_success = 0;
	const int result_failure = 1;

	// Warp Response Result Code
	namespace ResultCode
	{
		enum
		{
			success = 0,
			auth_error = 1,
			resource_not_found = 2,
			resource_moved = 3,
			bad_request = 4,	
			connection_error = 5,	
			unknown_error = 6,
			size_error = 7,
			api_not_found = 8
		};
	}

	//Message Type
	namespace MessageType
	{
		enum
		{
			request = 0,
			response = 1,
			update = 2
		};
	}

	//Request Type
	namespace RequestType
	{
		enum
		{
			auth = 1,
			join_lobby = 2,
			subscribe_lobby = 3, 
			unsubscribe_lobby = 4,  
			leave_lobby = 5,   
			create_room = 6,   
			join_room = 7,   
			subscribe_room = 8,   
			unsubscribe_room = 9,   
			leave_room = 10,   
			delete_room = 11,   
			chat = 12,   
			update_peers = 13,   
			signout = 14,
			create_zone = 15,
			delete_zone = 16, 
			get_rooms = 17,
			get_users = 18,
			get_user_info = 19,
			get_room_info = 20,
			set_custom_room_data = 21,
			set_custom_user_data = 22,        
			get_lobby_info = 23,
			//MatchMaking
			join_room_n_user = 24,
			update_room_property = 25,
			join_room_with_properties = 27,
			get_room_with_n_user = 28,
			get_room_with_properties = 29
		};
	}

	//Payload Type
	namespace PayLoadType
	{
		enum{
			flat_string = 0, 
			binary = 1,    
			json = 2
		};
	}

	//Update Type
	namespace UpdateType
	{
		enum
		{
			room_created = 1,
			room_deleted = 2,
			user_joined_lobby = 3,
			user_left_lobby = 4,
			user_joined_room = 5,
			user_left_room = 6,
			user_online = 7,
			user_offline = 8,
			chat = 9,
			update_peers = 10,
			//MatchMaking
			room_property_change = 11
		};
	}

	struct lobby_struct
	{
		std::string lobbyid;
		std::string owner;
		int maxUsers;
		std::string name;
		bool isPrimary;
		int result;
	};
	typedef lobby_struct lobby; 

	struct room_struct
	{
		std::string roomId;
		std::string owner;
		int maxUsers;
		std::string name;
		int result;
	};
	typedef room_struct room; 

	struct livelobby_struct
	{
		room rm;
		std::string customData;
		std::vector<std::string> users;
		int result;
	};
	typedef livelobby_struct livelobby; 

	struct liveroom_struct
	{
		room rm;
		std::string customData;
		std::vector<std::string> users;
		std::map<std::string, std::string> properties;
		int result;
	};
	typedef liveroom_struct liveroom;

	struct liveuser_struct
	{
		std::string name;
		std::string locationId;
		std::string customData;
		int result;
	};
	typedef liveuser_struct liveuser;

	struct liveresult_struct
	{
		int result;
		std::vector<std::string> list;
	};
	typedef liveresult_struct liveresult;

	struct matchedroom_struct
	{
		int result;
		std::vector<room> roomData;
	};
	typedef matchedroom_struct matchedroom;

	struct chat_struct
	{
		std::string chat;
		std::string sender;
		int locid;
		bool isLocationLobby;
		int result;
	};
	typedef chat_struct chat;
}