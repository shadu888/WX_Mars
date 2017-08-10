// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 1.0.1.
// **********************************************************************

#ifndef __TMTP_H_
#define __TMTP_H_

#include <map>
#include <string>
#include <vector>
#include "Tars.h"
using namespace std;

namespace MessageService
{
    enum CONNECT_RESULT
    {
        CONNECT_RESULT_SUCCESS = 0,
        CONNECT_RESULT_ERROR_PROTOCOL = 81,
        CONNECT_RESULT_ERROR_INDICATE = 82,
        CONNECT_RESULT_SERVICE_UNAVAILABLE = 83,
        CONNECT_RESULT_ERROR_USERNAME_OR_PASSWORD = 84,
        CONNECT_RESULT_KICKOUT = 85,
        CONNECT_RESULT_OTHER = 86,
    };
    inline string etos(const CONNECT_RESULT & e)
    {
        switch(e)
        {
            case CONNECT_RESULT_SUCCESS: return "CONNECT_RESULT_SUCCESS";
            case CONNECT_RESULT_ERROR_PROTOCOL: return "CONNECT_RESULT_ERROR_PROTOCOL";
            case CONNECT_RESULT_ERROR_INDICATE: return "CONNECT_RESULT_ERROR_INDICATE";
            case CONNECT_RESULT_SERVICE_UNAVAILABLE: return "CONNECT_RESULT_SERVICE_UNAVAILABLE";
            case CONNECT_RESULT_ERROR_USERNAME_OR_PASSWORD: return "CONNECT_RESULT_ERROR_USERNAME_OR_PASSWORD";
            case CONNECT_RESULT_KICKOUT: return "CONNECT_RESULT_KICKOUT";
            case CONNECT_RESULT_OTHER: return "CONNECT_RESULT_OTHER";
            default: return "";
        }
    }
    inline int stoe(const string & s, CONNECT_RESULT & e)
    {
        if(s == "CONNECT_RESULT_SUCCESS")  { e=CONNECT_RESULT_SUCCESS; return 0;}
        if(s == "CONNECT_RESULT_ERROR_PROTOCOL")  { e=CONNECT_RESULT_ERROR_PROTOCOL; return 0;}
        if(s == "CONNECT_RESULT_ERROR_INDICATE")  { e=CONNECT_RESULT_ERROR_INDICATE; return 0;}
        if(s == "CONNECT_RESULT_SERVICE_UNAVAILABLE")  { e=CONNECT_RESULT_SERVICE_UNAVAILABLE; return 0;}
        if(s == "CONNECT_RESULT_ERROR_USERNAME_OR_PASSWORD")  { e=CONNECT_RESULT_ERROR_USERNAME_OR_PASSWORD; return 0;}
        if(s == "CONNECT_RESULT_KICKOUT")  { e=CONNECT_RESULT_KICKOUT; return 0;}
        if(s == "CONNECT_RESULT_OTHER")  { e=CONNECT_RESULT_OTHER; return 0;}

        return -1;
    }

    enum GROUP_RESULT
    {
        GROUP_RESULT_SUCCESS = 0,
        GROUP_RESULT_GROUP_ID_NULL = 1,
        GROUP_RESULT_GROUP_ID_OVERLENGTH = 2,
        GROUP_RESULT_CLIENT_ID_ERROR = 3,
        GROUP_RESULT_DB_ERR = 4,
        GROUP_RESULT_OTHER = 5,
    };
    inline string etos(const GROUP_RESULT & e)
    {
        switch(e)
        {
            case GROUP_RESULT_SUCCESS: return "GROUP_RESULT_SUCCESS";
            case GROUP_RESULT_GROUP_ID_NULL: return "GROUP_RESULT_GROUP_ID_NULL";
            case GROUP_RESULT_GROUP_ID_OVERLENGTH: return "GROUP_RESULT_GROUP_ID_OVERLENGTH";
            case GROUP_RESULT_CLIENT_ID_ERROR: return "GROUP_RESULT_CLIENT_ID_ERROR";
            case GROUP_RESULT_DB_ERR: return "GROUP_RESULT_DB_ERR";
            case GROUP_RESULT_OTHER: return "GROUP_RESULT_OTHER";
            default: return "";
        }
    }
    inline int stoe(const string & s, GROUP_RESULT & e)
    {
        if(s == "GROUP_RESULT_SUCCESS")  { e=GROUP_RESULT_SUCCESS; return 0;}
        if(s == "GROUP_RESULT_GROUP_ID_NULL")  { e=GROUP_RESULT_GROUP_ID_NULL; return 0;}
        if(s == "GROUP_RESULT_GROUP_ID_OVERLENGTH")  { e=GROUP_RESULT_GROUP_ID_OVERLENGTH; return 0;}
        if(s == "GROUP_RESULT_CLIENT_ID_ERROR")  { e=GROUP_RESULT_CLIENT_ID_ERROR; return 0;}
        if(s == "GROUP_RESULT_DB_ERR")  { e=GROUP_RESULT_DB_ERR; return 0;}
        if(s == "GROUP_RESULT_OTHER")  { e=GROUP_RESULT_OTHER; return 0;}

        return -1;
    }

    enum MESSAGE_RESULT
    {
        MESSAGE_RESULT_SUCCESS = 0,
    };
    inline string etos(const MESSAGE_RESULT & e)
    {
        switch(e)
        {
            case MESSAGE_RESULT_SUCCESS: return "MESSAGE_RESULT_SUCCESS";
            default: return "";
        }
    }
    inline int stoe(const string & s, MESSAGE_RESULT & e)
    {
        if(s == "MESSAGE_RESULT_SUCCESS")  { e=MESSAGE_RESULT_SUCCESS; return 0;}

        return -1;
    }

    struct LoginReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.LoginReq";
        }
        static string MD5()
        {
            return "f608f7c81a12477dc352fbb6402712e3";
        }
        LoginReq()
        :appId(""),userId(""),userName(""),token(""),deviceType(0),deviceToken("")
        {
        }
        void resetDefautlt()
        {
            appId = "";
            userId = "";
            userName = "";
            token = "";
            deviceType = 0;
            deviceToken = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(appId, 0);
            _os.write(userId, 1);
            _os.write(userName, 2);
            _os.write(token, 3);
            _os.write(deviceType, 4);
            _os.write(deviceToken, 5);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(appId, 0, true);
            _is.read(userId, 1, true);
            _is.read(userName, 2, true);
            _is.read(token, 3, true);
            _is.read(deviceType, 4, true);
            _is.read(deviceToken, 5, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(appId,"appId");
            _ds.display(userId,"userId");
            _ds.display(userName,"userName");
            _ds.display(token,"token");
            _ds.display(deviceType,"deviceType");
            _ds.display(deviceToken,"deviceToken");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(appId, true);
            _ds.displaySimple(userId, true);
            _ds.displaySimple(userName, true);
            _ds.displaySimple(token, true);
            _ds.displaySimple(deviceType, true);
            _ds.displaySimple(deviceToken, false);
            return _os;
        }
    public:
        std::string appId;
        std::string userId;
        std::string userName;
        std::string token;
        tars::Short deviceType;
        std::string deviceToken;
    };
    inline bool operator==(const LoginReq&l, const LoginReq&r)
    {
        return l.appId == r.appId && l.userId == r.userId && l.userName == r.userName && l.token == r.token && l.deviceType == r.deviceType && l.deviceToken == r.deviceToken;
    }
    inline bool operator!=(const LoginReq&l, const LoginReq&r)
    {
        return !(l == r);
    }

    struct LoginResp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.LoginResp";
        }
        static string MD5()
        {
            return "f1833e406b1a8d8d08d96538c1f9ea2d";
        }
        LoginResp()
        :code(MessageService::CONNECT_RESULT_SUCCESS),info(""),server_timeout(20)
        {
        }
        void resetDefautlt()
        {
            info = "";
            server_timeout = 20;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write((tars::Int32)code, 0);
            if (info != "")
            {
                _os.write(info, 1);
            }
            if (server_timeout != 20)
            {
                _os.write(server_timeout, 2);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            tars::Int32 eTemp0 = MessageService::CONNECT_RESULT_SUCCESS;
            _is.read(eTemp0, 0, true);
            code = (MessageService::CONNECT_RESULT)eTemp0;
            _is.read(info, 1, false);
            _is.read(server_timeout, 2, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display((tars::Int32)code,"code");
            _ds.display(info,"info");
            _ds.display(server_timeout,"server_timeout");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple((tars::Int32)code, true);
            _ds.displaySimple(info, true);
            _ds.displaySimple(server_timeout, false);
            return _os;
        }
    public:
        MessageService::CONNECT_RESULT code;
        std::string info;
        tars::Int32 server_timeout;
    };
    inline bool operator==(const LoginResp&l, const LoginResp&r)
    {
        return l.code == r.code && l.info == r.info && l.server_timeout == r.server_timeout;
    }
    inline bool operator!=(const LoginResp&l, const LoginResp&r)
    {
        return !(l == r);
    }

    struct GroupReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.GroupReq";
        }
        static string MD5()
        {
            return "c9297db2d658badddcde8e004c809945";
        }
        GroupReq()
        :msg_id(""),group_id("")
        {
        }
        void resetDefautlt()
        {
            msg_id = "";
            group_id = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msg_id, 0);
            _os.write(group_id, 1);
            _os.write(client_ids, 2);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msg_id, 0, true);
            _is.read(group_id, 1, true);
            _is.read(client_ids, 2, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msg_id,"msg_id");
            _ds.display(group_id,"group_id");
            _ds.display(client_ids,"client_ids");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msg_id, true);
            _ds.displaySimple(group_id, true);
            _ds.displaySimple(client_ids, false);
            return _os;
        }
    public:
        std::string msg_id;
        std::string group_id;
        vector<std::string> client_ids;
    };
    inline bool operator==(const GroupReq&l, const GroupReq&r)
    {
        return l.msg_id == r.msg_id && l.group_id == r.group_id && l.client_ids == r.client_ids;
    }
    inline bool operator!=(const GroupReq&l, const GroupReq&r)
    {
        return !(l == r);
    }

    struct GroupResp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.GroupResp";
        }
        static string MD5()
        {
            return "0ba121ff952756a82c518fea0bb879e9";
        }
        GroupResp()
        :msg_id(""),code(MessageService::GROUP_RESULT_SUCCESS)
        {
        }
        void resetDefautlt()
        {
            msg_id = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msg_id, 0);
            _os.write((tars::Int32)code, 1);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msg_id, 0, true);
            tars::Int32 eTemp1 = MessageService::GROUP_RESULT_SUCCESS;
            _is.read(eTemp1, 1, true);
            code = (MessageService::GROUP_RESULT)eTemp1;
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msg_id,"msg_id");
            _ds.display((tars::Int32)code,"code");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msg_id, true);
            _ds.displaySimple((tars::Int32)code, false);
            return _os;
        }
    public:
        std::string msg_id;
        MessageService::GROUP_RESULT code;
    };
    inline bool operator==(const GroupResp&l, const GroupResp&r)
    {
        return l.msg_id == r.msg_id && l.code == r.code;
    }
    inline bool operator!=(const GroupResp&l, const GroupResp&r)
    {
        return !(l == r);
    }

    struct MsgReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.MsgReq";
        }
        static string MD5()
        {
            return "a1edde08817ba65f29558ba6851b5d10";
        }
        MsgReq()
        :msg_id(""),seq_id(0),timestamp(0),expire_time(0),from(""),to(""),to_client_id(""),pushinfo(""),status(0),priority(0)
        {
        }
        void resetDefautlt()
        {
            msg_id = "";
            seq_id = 0;
            timestamp = 0;
            expire_time = 0;
            from = "";
            to = "";
            to_client_id = "";
            pushinfo = "";
            status = 0;
            priority = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msg_id, 0);
            if (seq_id != 0)
            {
                _os.write(seq_id, 1);
            }
            if (timestamp != 0)
            {
                _os.write(timestamp, 2);
            }
            if (expire_time != 0)
            {
                _os.write(expire_time, 3);
            }
            _os.write(from, 4);
            _os.write(to, 5);
            if (to_client_id != "")
            {
                _os.write(to_client_id, 6);
            }
            if (pushinfo != "")
            {
                _os.write(pushinfo, 7);
            }
            if (content.size() > 0)
            {
                _os.write(content, 8);
            }
            if (status != 0)
            {
                _os.write(status, 9);
            }
            if (priority != 0)
            {
                _os.write(priority, 10);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msg_id, 0, true);
            _is.read(seq_id, 1, false);
            _is.read(timestamp, 2, false);
            _is.read(expire_time, 3, false);
            _is.read(from, 4, true);
            _is.read(to, 5, true);
            _is.read(to_client_id, 6, false);
            _is.read(pushinfo, 7, false);
            _is.read(content, 8, false);
            _is.read(status, 9, false);
            _is.read(priority, 10, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msg_id,"msg_id");
            _ds.display(seq_id,"seq_id");
            _ds.display(timestamp,"timestamp");
            _ds.display(expire_time,"expire_time");
            _ds.display(from,"from");
            _ds.display(to,"to");
            _ds.display(to_client_id,"to_client_id");
            _ds.display(pushinfo,"pushinfo");
            _ds.display(content,"content");
            _ds.display(status,"status");
            _ds.display(priority,"priority");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msg_id, true);
            _ds.displaySimple(seq_id, true);
            _ds.displaySimple(timestamp, true);
            _ds.displaySimple(expire_time, true);
            _ds.displaySimple(from, true);
            _ds.displaySimple(to, true);
            _ds.displaySimple(to_client_id, true);
            _ds.displaySimple(pushinfo, true);
            _ds.displaySimple(content, true);
            _ds.displaySimple(status, true);
            _ds.displaySimple(priority, false);
            return _os;
        }
    public:
        std::string msg_id;
        tars::Int64 seq_id;
        tars::Int64 timestamp;
        tars::Int64 expire_time;
        std::string from;
        std::string to;
        std::string to_client_id;
        std::string pushinfo;
        vector<tars::Char> content;
        tars::Int32 status;
        tars::Int32 priority;
    };
    inline bool operator==(const MsgReq&l, const MsgReq&r)
    {
        return l.msg_id == r.msg_id && l.seq_id == r.seq_id && l.timestamp == r.timestamp && l.expire_time == r.expire_time && l.from == r.from && l.to == r.to && l.to_client_id == r.to_client_id && l.pushinfo == r.pushinfo && l.content == r.content && l.status == r.status && l.priority == r.priority;
    }
    inline bool operator!=(const MsgReq&l, const MsgReq&r)
    {
        return !(l == r);
    }

    struct MsgAck : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.MsgAck";
        }
        static string MD5()
        {
            return "bb3b77f3c06f2c719d51dd0b4628ad35";
        }
        MsgAck()
        :msg_id(""),seq_id(0),type(0),from(""),to(""),priority(0)
        {
        }
        void resetDefautlt()
        {
            msg_id = "";
            seq_id = 0;
            type = 0;
            from = "";
            to = "";
            priority = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            if (msg_id != "")
            {
                _os.write(msg_id, 0);
            }
            if (seq_id != 0)
            {
                _os.write(seq_id, 1);
            }
            if (type != 0)
            {
                _os.write(type, 2);
            }
            if (from != "")
            {
                _os.write(from, 3);
            }
            if (to != "")
            {
                _os.write(to, 4);
            }
            if (priority != 0)
            {
                _os.write(priority, 5);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msg_id, 0, false);
            _is.read(seq_id, 1, false);
            _is.read(type, 2, false);
            _is.read(from, 3, false);
            _is.read(to, 4, false);
            _is.read(priority, 5, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msg_id,"msg_id");
            _ds.display(seq_id,"seq_id");
            _ds.display(type,"type");
            _ds.display(from,"from");
            _ds.display(to,"to");
            _ds.display(priority,"priority");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msg_id, true);
            _ds.displaySimple(seq_id, true);
            _ds.displaySimple(type, true);
            _ds.displaySimple(from, true);
            _ds.displaySimple(to, true);
            _ds.displaySimple(priority, false);
            return _os;
        }
    public:
        std::string msg_id;
        tars::Int64 seq_id;
        tars::Int32 type;
        std::string from;
        std::string to;
        tars::Int32 priority;
    };
    inline bool operator==(const MsgAck&l, const MsgAck&r)
    {
        return l.msg_id == r.msg_id && l.seq_id == r.seq_id && l.type == r.type && l.from == r.from && l.to == r.to && l.priority == r.priority;
    }
    inline bool operator!=(const MsgAck&l, const MsgAck&r)
    {
        return !(l == r);
    }

    struct OffMsgCountItem : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.OffMsgCountItem";
        }
        static string MD5()
        {
            return "e121cda4a69266101672fd95d1950a8e";
        }
        OffMsgCountItem()
        :type(0),seq_id(0)
        {
        }
        void resetDefautlt()
        {
            type = 0;
            seq_id = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(type, 2);
            _os.write(seq_id, 3);
            if (msgs.size() > 0)
            {
                _os.write(msgs, 4);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(type, 2, true);
            _is.read(seq_id, 3, true);
            _is.read(msgs, 4, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(type,"type");
            _ds.display(seq_id,"seq_id");
            _ds.display(msgs,"msgs");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(type, true);
            _ds.displaySimple(seq_id, true);
            _ds.displaySimple(msgs, false);
            return _os;
        }
    public:
        tars::Int32 type;
        tars::Int64 seq_id;
        vector<MessageService::MsgReq> msgs;
    };
    inline bool operator==(const OffMsgCountItem&l, const OffMsgCountItem&r)
    {
        return l.type == r.type && l.seq_id == r.seq_id && l.msgs == r.msgs;
    }
    inline bool operator!=(const OffMsgCountItem&l, const OffMsgCountItem&r)
    {
        return !(l == r);
    }

    struct OffMsgCountResp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.OffMsgCountResp";
        }
        static string MD5()
        {
            return "e3681f1f39e3fcec7d3ee7dd6ab81127";
        }
        OffMsgCountResp()
        :code(0)
        {
        }
        void resetDefautlt()
        {
            code = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msg_counts, 0);
            if (code != 0)
            {
                _os.write(code, 1);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msg_counts, 0, true);
            _is.read(code, 1, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msg_counts,"msg_counts");
            _ds.display(code,"code");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msg_counts, true);
            _ds.displaySimple(code, false);
            return _os;
        }
    public:
        vector<MessageService::OffMsgCountItem> msg_counts;
        tars::Int32 code;
    };
    inline bool operator==(const OffMsgCountResp&l, const OffMsgCountResp&r)
    {
        return l.msg_counts == r.msg_counts && l.code == r.code;
    }
    inline bool operator!=(const OffMsgCountResp&l, const OffMsgCountResp&r)
    {
        return !(l == r);
    }

    struct OffMsgCountACK : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.OffMsgCountACK";
        }
        static string MD5()
        {
            return "780e2f8084d5e1e3996b84253499c750";
        }
        OffMsgCountACK()
        {
        }
        void resetDefautlt()
        {
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(acks, 0);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(acks, 0, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(acks,"acks");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(acks, false);
            return _os;
        }
    public:
        vector<MessageService::MsgAck> acks;
    };
    inline bool operator==(const OffMsgCountACK&l, const OffMsgCountACK&r)
    {
        return l.acks == r.acks;
    }
    inline bool operator!=(const OffMsgCountACK&l, const OffMsgCountACK&r)
    {
        return !(l == r);
    }

    struct PresenceReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.PresenceReq";
        }
        static string MD5()
        {
            return "b84e4dd5dd1d7c43dbe702512024405f";
        }
        PresenceReq()
        :msgId(0),userId("")
        {
        }
        void resetDefautlt()
        {
            msgId = 0;
            userId = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msgId, 0);
            _os.write(userId, 1);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msgId, 0, true);
            _is.read(userId, 1, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msgId,"msgId");
            _ds.display(userId,"userId");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msgId, true);
            _ds.displaySimple(userId, false);
            return _os;
        }
    public:
        tars::Int32 msgId;
        std::string userId;
    };
    inline bool operator==(const PresenceReq&l, const PresenceReq&r)
    {
        return l.msgId == r.msgId && l.userId == r.userId;
    }
    inline bool operator!=(const PresenceReq&l, const PresenceReq&r)
    {
        return !(l == r);
    }

    struct OffMsgItem : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.OffMsgItem";
        }
        static string MD5()
        {
            return "facbc1c2ab9cfc9413dceb13db2d09af";
        }
        OffMsgItem()
        :type(0)
        {
        }
        void resetDefautlt()
        {
            type = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(type, 0);
            _os.write(item, 1);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(type, 0, true);
            _is.read(item, 1, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(type,"type");
            _ds.display(item,"item");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(type, true);
            _ds.displaySimple(item, false);
            return _os;
        }
    public:
        tars::Int32 type;
        MessageService::MsgReq item;
    };
    inline bool operator==(const OffMsgItem&l, const OffMsgItem&r)
    {
        return l.type == r.type && l.item == r.item;
    }
    inline bool operator!=(const OffMsgItem&l, const OffMsgItem&r)
    {
        return !(l == r);
    }

    struct OffMsgResp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.OffMsgResp";
        }
        static string MD5()
        {
            return "2a303037656ad89a8d729168177a3a30";
        }
        OffMsgResp()
        :code(0)
        {
        }
        void resetDefautlt()
        {
            code = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(msgs, 0);
            if (code != 0)
            {
                _os.write(code, 1);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(msgs, 0, true);
            _is.read(code, 1, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(msgs,"msgs");
            _ds.display(code,"code");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(msgs, true);
            _ds.displaySimple(code, false);
            return _os;
        }
    public:
        vector<MessageService::OffMsgItem> msgs;
        tars::Int32 code;
    };
    inline bool operator==(const OffMsgResp&l, const OffMsgResp&r)
    {
        return l.msgs == r.msgs && l.code == r.code;
    }
    inline bool operator!=(const OffMsgResp&l, const OffMsgResp&r)
    {
        return !(l == r);
    }

    struct MonitorResp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "MessageService.MonitorResp";
        }
        static string MD5()
        {
            return "8106794cf632e731bac2d2c7b3d02723";
        }
        MonitorResp()
        :broker_id(""),user_online(0),send_msgs(0),recv_msgs(0)
        {
        }
        void resetDefautlt()
        {
            broker_id = "";
            user_online = 0;
            send_msgs = 0;
            recv_msgs = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            if (broker_id != "")
            {
                _os.write(broker_id, 0);
            }
            if (user_online != 0)
            {
                _os.write(user_online, 1);
            }
            if (send_msgs != 0)
            {
                _os.write(send_msgs, 2);
            }
            if (recv_msgs != 0)
            {
                _os.write(recv_msgs, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(broker_id, 0, false);
            _is.read(user_online, 1, false);
            _is.read(send_msgs, 2, false);
            _is.read(recv_msgs, 3, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(broker_id,"broker_id");
            _ds.display(user_online,"user_online");
            _ds.display(send_msgs,"send_msgs");
            _ds.display(recv_msgs,"recv_msgs");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(broker_id, true);
            _ds.displaySimple(user_online, true);
            _ds.displaySimple(send_msgs, true);
            _ds.displaySimple(recv_msgs, false);
            return _os;
        }
    public:
        std::string broker_id;
        tars::Int32 user_online;
        tars::Int32 send_msgs;
        tars::Int32 recv_msgs;
    };
    inline bool operator==(const MonitorResp&l, const MonitorResp&r)
    {
        return l.broker_id == r.broker_id && l.user_online == r.user_online && l.send_msgs == r.send_msgs && l.recv_msgs == r.recv_msgs;
    }
    inline bool operator!=(const MonitorResp&l, const MonitorResp&r)
    {
        return !(l == r);
    }
}

#endif