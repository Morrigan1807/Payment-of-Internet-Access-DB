#pragma once
#include "ChangeLogItem.h"
#include "AddComputer.h"
#include "AddConnections.h"
#include "AddOperator.h"
#include "AddPrice.h"
#include "AddSeance.h"
#include "AddShift.h"
#include "AddShiftOperator.h"
#include "Max_Clients.h"
#include "NewReport.h"
#include "Num_of_clients.h"
#include "ShiftOperators.h"
namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;
	using namespace System::Collections::Generic;

	/// <summary>
	/// ������ ��� General
	/// </summary>
	public ref class General : public System::Windows::Forms::Form
	{
	public:
		General(void)
		{
			InitializeComponent();
			this->dataGridView1->Size = System::Drawing::Size(this->Size.Width - this->dataGridView1->Location.X-50,
				this->Size.Height - this->dataGridView1->Location.Y-50);
			this->ChangeLog = gcnew Generic::Queue<ChangeLogItem^>();
			//
			//TODO: �������� ��� ������������
			//
			
		}
		void priority_power()
		{
			switch (this->type_of_user)
			{
			case 1:
				this->������ToolStripMenuItem->Visible = false;
				this->����������ToolStripMenuItem->Visible = false;
				break;
			case 2:
				this->����������ToolStripMenuItem->Visible = false;
				this->�����ToolStripMenuItem->Visible = false;
				this->����������ToolStripMenuItem->Visible = false;
				this->����������ToolStripMenuItem->Visible = false;
				this->���������������ToolStripMenuItem->Visible = false;
				break;
			default:
				break;
			}
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~General()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	public: int type_of_user;
			int user;
			int count_table = -1;
			Form^ log;
	private: Generic::Queue<ChangeLogItem^>^ ChangeLog;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �ToolStripMenuItem;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(General::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->�������ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(803, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������������ToolStripMenuItem,
					this->�����������������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->��������������ToolStripMenuItem->Text = L"����� �� ��������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::��������������ToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->�����������������ToolStripMenuItem->Text = L"������� ����������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::�����������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->����������ToolStripMenuItem,
					this->������ToolStripMenuItem, this->�����ToolStripMenuItem, this->����������ToolStripMenuItem, this->����������ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::����������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::�����ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::����������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::����������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->���������������ToolStripMenuItem->Text = L"���������� �����";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::���������������ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->���������������������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�ToolStripMenuItem
			});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->���������������������ToolStripMenuItem->Text = L"������������ ���������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::���������������������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->������������������ToolStripMenuItem,
					this->�������������������������������������ToolStripMenuItem
			});
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(326, 22);
			this->������������������ToolStripMenuItem->Text = L"���������� �������� �� �����";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::������������������ToolStripMenuItem_Click);
			// 
			// �������������������������������������ToolStripMenuItem
			// 
			this->�������������������������������������ToolStripMenuItem->Name = L"�������������������������������������ToolStripMenuItem";
			this->�������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(326, 22);
			this->�������������������������������������ToolStripMenuItem->Text = L"������������ ���������� �������� �� �����";
			this->�������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::�������������������������������������ToolStripMenuItem_Click);
			// 
			// �ToolStripMenuItem
			// 
			this->�ToolStripMenuItem->Name = L"�ToolStripMenuItem";
			this->�ToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->�ToolStripMenuItem->Text = L"������ ����������� �����";
			this->�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::�ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &General::�������ToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(12, 109);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(779, 355);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &General::dataGridView1_CellEndEdit);
			this->dataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &General::dataGridView1_UserDeletingRow);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 39);
			this->button1->TabIndex = 2;
			this->button1->Text = L"��������� ���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &General::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(707, 45);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 37);
			this->button2->TabIndex = 3;
			this->button2->Text = L"�������� �������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &General::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(23, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 37);
			this->button3->TabIndex = 4;
			this->button3->Text = L"�������� ������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &General::button3_Click);
			// 
			// General
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(803, 476);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"General";
			this->Text = L"�������";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &General::General_FormClosed);
			this->Resize += gcnew System::EventHandler(this, &General::General_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT Computer_number, IP_adress FROM Computers";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 2;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "����� ����������";
		dataGridView1->Columns[1]->HeaderText = "IP �����";

		while (dr->Read())
		{
			dataGridView1->Rows->Add(dr[0]->ToString(), dr[1]->ToString());
		}
		dr->Close();
		connect->Close();
		count_table = 0;
	}
	private: System::Void ������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT Computer_number, S_date, ID_connection, Operator_number, ID_price, ID_shift FROM Seance";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 7;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "�";
		dataGridView1->Columns[1]->HeaderText = "����� ����������";
		dataGridView1->Columns[2]->HeaderText = "���� ����������";
		dataGridView1->Columns[3]->HeaderText = "ID ����������";
		dataGridView1->Columns[4]->HeaderText = "����� ���������";
		dataGridView1->Columns[5]->HeaderText = "ID ����";
		dataGridView1->Columns[6]->HeaderText = "ID �����";

		int i = 1;
		while (dr->Read())
		{
			dataGridView1->Rows->Add(i.ToString(), dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(),
				dr[3]->ToString(), dr[4]->ToString(), dr[5]->ToString());
			i++;
		}
		dr->Close();
		connect->Close();
		count_table = 1;
	}
	private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT ID_shift, Shift_number, DT_start, DT_end FROM Shifts";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 4;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "ID �����";
		dataGridView1->Columns[1]->HeaderText = "����� �����";
		dataGridView1->Columns[2]->HeaderText = "���� � ����� ������ �����";
		dataGridView1->Columns[3]->HeaderText = "���� � ����� ��������� �����";

		while (dr->Read())
		{
			dataGridView1->Rows->Add(dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(),
				dr[3]->ToString());
		}
		dr->Close();
		connect->Close();
		count_table = 2;
	}
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT ID_connection, T_start, T_end, Num_of_min FROM Connections";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 4;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "ID ����������";
		dataGridView1->Columns[1]->HeaderText = "����� ������";
		dataGridView1->Columns[2]->HeaderText = "����� ���������";
		dataGridView1->Columns[3]->HeaderText = "���������� �����";

		while (dr->Read())
		{
			dataGridView1->Rows->Add(dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(),
				dr[3]->ToString());
		}
		dr->Close();
		connect->Close();
		count_table = 3;
	}
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT Operator_number, Full_name, Position, Adress, Telephone, U_login FROM Operators";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 6;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "����� ���������";
		dataGridView1->Columns[1]->HeaderText = "���";
		dataGridView1->Columns[2]->HeaderText = "���������";
		dataGridView1->Columns[3]->HeaderText = "�������� �����";
		dataGridView1->Columns[4]->HeaderText = "������ �������";
		dataGridView1->Columns[5]->HeaderText = "����� � �������";

		while (dr->Read())
		{
			dataGridView1->Rows->Add(dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(),
				dr[3]->ToString(), dr[4]->ToString(), dr[5]->ToString());
		}
		dr->Close();
		connect->Close();
		count_table = 4;
	}
	private: System::Void ���������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT ID_shift, Operator_number FROM Shift_operators";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 3;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "�";
		dataGridView1->Columns[1]->HeaderText = "ID �����";
		dataGridView1->Columns[2]->HeaderText = "����� ���������";

		int i = 1;
		while (dr->Read())
		{
			dataGridView1->Rows->Add(i.ToString(), dr[0]->ToString(), dr[1]->ToString());
			i++;
		}
		dr->Close();
		connect->Close();
		count_table = 5;
	}
	private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->CommandText = "SELECT ID_price, P_date, CPM, CPM_20_2, CPM_2_6 FROM Prices";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		dataGridView1->ColumnCount = 5;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns[0]->HeaderText = "ID ����";
		dataGridView1->Columns[1]->HeaderText = "����";
		dataGridView1->Columns[2]->HeaderText = "��������� ����� ������";
		dataGridView1->Columns[3]->HeaderText = "������ � 20:00 �� 2:00";
		dataGridView1->Columns[4]->HeaderText = "������ � 2:00 �� 6:00";

		while (dr->Read())
		{
			dataGridView1->Rows->Add(dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(),
				dr[3]->ToString(), dr[4]->ToString());
		}
		dr->Close();
		connect->Close();
		count_table = 6;
	}
	private: System::Void General_Resize(System::Object^  sender, System::EventArgs^  e)
	{
		this->dataGridView1->Size = System::Drawing::Size(this->Size.Width - this->dataGridView1->Location.X-50,
			this->Size.Height - this->dataGridView1->Location.Y-50);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		while (ChangeLog->Count != 0)
		{
			ChangeLog->Dequeue()->applyChange();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		switch (count_table)
		{
		case 0:
			����������ToolStripMenuItem_Click(sender, e);
			break;
		case 1:
			������ToolStripMenuItem_Click(sender, e);
			break;
		case 2:
			�����ToolStripMenuItem_Click(sender, e);
			break;
		case 3:
			����������ToolStripMenuItem_Click(sender, e);
			break;
		case 4:
			����������ToolStripMenuItem_Click(sender, e);
			break;
		case 5:
			���������������ToolStripMenuItem_Click(sender, e);
			break;
		case 6:
			����ToolStripMenuItem_Click(sender, e);
			break;
		default:
			MessageBox::Show("������! ��������� �������.");
			break;
		}
	}
	private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("������ ��������� ���� ����������� � �������� ��������� ������� � �� ����� ���� ������������ � �������� ������������ ��������."
			+ "\n��������� ����������� � 2019 ����. �����������: ������� �.�. \n\n\t\t\t\t\t\t Just smile ;)");
	}
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
		log->Close();
	}
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Hide();
		log->ShowDialog();
		this->Close();
	}
	private: System::Void dataGridView1_UserDeletingRow(System::Object^  sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^  e)
	{
		switch (this->count_table)
		{
		case 0:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Computers", "DELETE");
			remove_row->fill_primary_key_field("Computer_number",
				e->Row->Cells[0]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		case 1:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Seance", "DELETE");
			remove_row->fill_primary_key_field("Computer_number",
				e->Row->Cells[1]->Value->ToString());
			remove_row->fill_primary_key_field("S_Date",
				"CONVERT(DATE,\'" + e->Row->Cells[2]->Value->ToString() + "\',104)");
			remove_row->fill_primary_key_field("ID_connection",
				e->Row->Cells[3]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);

			break;
		}
		case 2:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Shifts", "DELETE");
			remove_row->fill_primary_key_field("ID_shift",
				e->Row->Cells[0]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		case 3:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Connections", "DELETE");
			remove_row->fill_primary_key_field("ID_connection",
				e->Row->Cells[0]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		case 4:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Operators", "DELETE");
			remove_row->fill_primary_key_field("Operator_number",
				e->Row->Cells[0]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		case 5:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Shift_operators", "DELETE");
			remove_row->fill_primary_key_field("ID_shift",
				e->Row->Cells[1]->Value->ToString());
			remove_row->fill_primary_key_field("Operator_number",
				e->Row->Cells[2]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		case 6:
		{
			ChangeLogItem^ remove_row = gcnew ChangeLogItem("Prices", "DELETE");
			remove_row->fill_primary_key_field("ID_price",
				e->Row->Cells[0]->Value->ToString());
			this->ChangeLog->Enqueue(remove_row);
			break;
		}
		default:
			MessageBox::Show("������! ��������� �������.");
			break;
		}
	}
	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		switch (this->count_table)
		{
		case 0:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Computers", "UPDATE");
			edit_row->fill_primary_key_field("Computer_number",
				this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 1:
				edit_row->fill_row_update("IP_adress",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		case 1:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Seance", "UPDATE");
			edit_row->fill_primary_key_field("Computer_number",
				this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString());
			edit_row->fill_primary_key_field("S_Date",
				"CONVERT(DATE,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString() + "\',104)");
			edit_row->fill_primary_key_field("ID_connection",
				this->dataGridView1->Rows[e->RowIndex]->Cells[3]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 4:
				edit_row->fill_row_update("Operator_number",
					this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
				break;
			case 5:
				edit_row->fill_row_update("ID_price",
					this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
				break;
			case 6:
				edit_row->fill_row_update("ID_shift",
					this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		case 2:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Shifts", "UPDATE");
			edit_row->fill_primary_key_field("ID_shift",
				this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 1:
				edit_row->fill_row_update("Shift_number",
					this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
				break;
			case 2:
				edit_row->fill_row_update("DT_start",
					"CONVERT(DATETIME,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\',104)");
				break;
			case 3:
				edit_row->fill_row_update("DT_end",
					"CONVERT(DATETIME,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\',104)");
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		case 3:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Connections", "UPDATE");
			edit_row->fill_primary_key_field("ID_connection",
				this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 1:
				edit_row->fill_row_update("T_start",
					"CONVERT(TIME,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\',108)");
				break;
			case 2:
				edit_row->fill_row_update("T_end",
					"CONVERT(TIME,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\',108)");
				break;
			case 3:
				edit_row->fill_row_update("Num_of_min",
					this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		case 4:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Operators", "UPDATE");
			edit_row->fill_primary_key_field("Operator_number",
				this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 1:
				edit_row->fill_row_update("Full_name",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			case 2:
				edit_row->fill_row_update("Position",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			case 3:
				edit_row->fill_row_update("Adress",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			case 4:
				edit_row->fill_row_update("Telephone",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			case 5:
				edit_row->fill_row_update("U_login",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			case 6:
				edit_row->fill_row_update("U_password",
					"\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\'");
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		case 5:
			//this is now allowed in any way. "shift operators"
			break;
		case 6:
		{
			ChangeLogItem^ edit_row = gcnew ChangeLogItem("Prices", "UPDATE");
			edit_row->fill_primary_key_field("ID_price",
				this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
			switch (e->ColumnIndex)
			{
			case 1:
				edit_row->fill_row_update("P_date",
					"CONVERT(DATE,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\',104)");
				break;
			case 2:
				edit_row->fill_row_update("CPM",
					"CONVERT(MONEY,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\')");
				break;
			case 3:
				edit_row->fill_row_update("CPM_20_2",
					"CONVERT(MONEY,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\')");
				break;
			case 4:
				edit_row->fill_row_update("CPM_2_6",
					"CONVERT(MONEY,\'" + this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() + "\')");
				break;
			default:
				MessageBox::Show("������! ��������� ��������� ��������� ����������.");
				break;
			}
			this->ChangeLog->Enqueue(edit_row);
			break;
		}
		default:
			MessageBox::Show("������! ��������� �������.");
			break;
		}

	}
	private: System::Void General_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		log->Close();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		switch (count_table)
		{
		case 0:
		{
			AddComputer^ new_computer = gcnew AddComputer();
			new_computer->general = this;
			this->Enabled = false;
			new_computer->Show();
			break;
		}
		case 1:
		{
			AddSeance^ new_seance = gcnew AddSeance();
			new_seance->general = this;
			this->Enabled = false;
			new_seance->Show();
			break;
		}
		case 2:
		{
			AddShift^ new_shift = gcnew AddShift();
			new_shift->general = this;
			this->Enabled = false;
			new_shift->Show();
			break;
		}
		case 3:
		{
			AddConnections^ new_connection = gcnew AddConnections();
			new_connection->general = this;
			this->Enabled = false;
			new_connection->Show();
			break;
		}
		case 4:
		{
			AddOperator^ new_operator = gcnew AddOperator();
			new_operator->general = this;
			this->Enabled = false;
			new_operator->Show();
			break;
		}
		case 5:
		{
			AddShiftOperator^ new_shift_operator = gcnew AddShiftOperator();
			new_shift_operator->general = this;
			this->Enabled = false;
			new_shift_operator->Show();
			break;
		}
		case 6:
		{
			AddPrice^ new_price = gcnew AddPrice();
			new_price->general = this;
			this->Enabled = false;
			new_price->Show();
			break;
		}
		default:
			MessageBox::Show("������! ��������� �������.");
			break;
		}
	}
	private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		NewReport^ new_report = gcnew NewReport();
		new_report->general = this;
		new_report->user = this->user;
		this->Enabled = false;
		new_report->Show();
	}
private: System::Void ������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Num_of_clients^ new_num_of_clients = gcnew Num_of_clients();
	new_num_of_clients->general = this;
	this->Enabled = false;
	new_num_of_clients->Show();
}
private: System::Void �������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Max_Clients^ new_max_clients = gcnew Max_Clients();
	new_max_clients->general = this;
	this->Enabled = false;
	new_max_clients->Show();
}
private: System::Void �ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	ShiftOperators^ new_shift_operators = gcnew ShiftOperators();
	new_shift_operators->general = this;
	this->Enabled = false;
	new_shift_operators->Show();
}
};
}